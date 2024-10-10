var eventEmitter = io(); // event listener/emitter

let name = '';
let color = ''; //$("#color").val();

function fix(txt) { // strips off bad characters
    return txt.replace(/&/g, "&amp;")
        .replace(/</g, "&lt;")
        .replace(/>/g, "&gt;")
        .replace(/"/g, "&quot;")
        .replace(/'/g, "&#039;");
}



eventEmitter.on("newmsg", (name, color, msg) => { // receive new msg
    msg = fix(msg)
    color = fix(color)

    $("#chat").prepend('<p class="'+color+'"><b>&lt;'+name+'&gt;</b>&nbsp;'+msg+'</p>');
});

eventEmitter.on("servermsg", (msg) => { // receive server msg
    $("#chat").prepend('<p><b>&lt;SYSTEM&gt;</b>&nbsp;<b>'+msg+'</b></p>');
});

eventEmitter.on("userchange", (name, color, oldName) => { // receive user update
    color = fix(color);
    if (oldName == '') oldName = "Anonymous";
    if (name == '') name = "Anonymous";
    
    $("#chat").prepend('<p>* <b>'+oldName+'</b> has changed their name to <b><span class='+color+'>'+name+'</span></b></p>');
});

eventEmitter.on("newjoin", (name, color) => {
    if (name == '') name = "Anonymous";
    $("#chat").prepend('<p>* <b>'+name+'</b> joined</p>');
});
eventEmitter.on("newleave", (name, color) => {
    if (name == '') name = "Anonymous";
    $("#chat").prepend('<p>* <b>'+name+'</b> left</p>');
});

chat = function() {
    // get values
    var msg = $("#msg").val();
    // force name
    if (name === '') name = "Anonymous";
    // dont send if empty message
    if (msg !== '') {
        $("#msg").val(''); // clear box
        eventEmitter.emit("chat", name, color, msg); // send event "chat" (to source.js)
    }
}
// also run 


checknew = function() { // check if the new data matches old data
    if ($("#name").val() !== name) $("#save").addClass('unsaved')
    else $("#save").removeClass('unsaved');
};

save = function() { // saved options
    if ($("#save").hasClass('unsaved')) {
        oldName = name;
        name = fix($("#name").val());
        $("#save").removeClass('unsaved');
        eventEmitter.emit("new", name, color, oldName); // send event "new" (to source.js)
    }
}

function checkenter(key) { // detects enter key - thanks stackoverflow
    let code = key.keyCode ? key.keyCode : key.which // key.keyCode if the browser uses keyCode, else use key.which
    if (code === 13) {
        chat(); // if code is enter, execute chat() to send the message
    }
};
function undoenter(key) { // detects enter key - thanks stackoverflow
    let code = key.keyCode ? key.keyCode : key.which // key.keyCode if the browser uses keyCode, else use key.which
    if (code === 13) {
        $("#msg").val(''); // clear box
    }
};


join = function() { // body onload
    eventEmitter.emit("join", name, color);
}
leave = function() { // body onunload
    eventEmitter.emit("leave", name, color);
}


/* channel list */

let cNameSet = '#...';
let cTextSet = 'Join or mouse over a channel to view its topic!';

function preview(channel) {
    switch (channel) {
        case 'general':
            cName = '#general';
            cText = 'The general channel for general people.';
            return
        case 'alternate':
            cName = '#alternate';
            cText = 'The alternate channel for less general people.';
            return
        case 'strange':
            cName = '#strange';
            cText = 'Why.';
            return
        default:
            return
    }
}