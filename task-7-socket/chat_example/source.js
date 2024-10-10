// obligatory
const express = require('express') // create module
let app = express(); // create an express object
const http = require('http').Server(app);
const io = require('socket.io')(http);
const mysql = require('mysql');
let con = mysql.createConnection({ // database connection object
  host: "localhost",
  user: "root",
  password: "hexanova7",
  database: "irc"
});

app.use(express.static(__dirname + '/public')); // thanks stackoverflow

io.on('connection', (socket) => { // is online

  socket.on('chat', (name, color, msg) => { // receive event "chat" (from index.html)
    console.log(name+": "+msg);
    socket.emit('newmsg', name, color, msg); // self
    socket.broadcast.emit('newmsg', name, color, msg); // all but self

    // RESPONSES
    /*let sql = `SELECT * FROM res WHERE ifthis = '${msg.toLowerCase()}'`

    con.query(sql, function (err, result, fields) {
      if (err) throw err; // crash the server if something goes wrong
      if (result.length === 0) return; // if no response found in database, stop function
      let ans = result[0].thenthat; // get response
      ans = ans.replace('%u', name); // replace placeholder with actual username
      socket.emit('servermsg', ans); // to self
      socket.broadcast.emit('servermsg', ans); // to all but self
    });*/

  });

  socket.on('new', (name, color, oldName) => { // when user has saved options
    console.log(oldName+" changed their name to "+name+" in color "+color);
    socket.emit('userchange', name, color, oldName); // self
    socket.broadcast.emit('userchange', name, color, oldName); // all but self
  });

  socket.on('join', (name, color) => { // new user join
    console.log(name+" joined");
    socket.emit('newjoin', name, color); // self
    socket.broadcast.emit('newjoin', name, color); // all but self
  });

  socket.on('leave', (name, color) => { // new user join
    console.log(name+" left");
    socket.emit('newleave', name, color); // self
    socket.broadcast.emit('newleave', name, color); // all but self
  });

});

http.listen(5000, function(){ // set port
  console.log('listening on *:5000');
});