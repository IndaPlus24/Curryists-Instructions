# 🥞 Task 15: Backwards Stackwards

The theme of next week's regular task is actually super relevant to low level programming so this week we're going to be working with *the stack!*

The stack is critically important to understand if you want to have any chance of ever becoming a *real* software engineer and escaping soy dev purgatory. One of the core uses of stacks in software development is the *call stack*, which is basically where we keep track of which functions are currently running and where they should return to.

Something I've always found to be very odd about the stack in systems programming is the fact that it grows *down*. That is to say: the first stack variables are at the highest memory address, and the following stack variables are at lower memory addresses.

I'm sure there's a good reason for it, but in my eyes that low key doesn't make sense. So let's correct it! **Your task for this week is to implement a call stack in MIPS assembly that grows from the bottom up instead of from the top down!**

## 📖 Resources

### Learn Assembly

- If you didn't do task-13+ or just need a refresher, here's a video by the YouTube channel Low Level (his stuff is amazing, highly recommend) that goes through some of the basics of writing in assembly: [you can become a GIGACHAD assembly programmer in 10 minutes (try it RIGHT NOW)](https://youtu.be/6S5KRJv-7RU?si=b5l9fqNV6zFNvxZ7)  
    **NOTE:** His tutorial is in x86 assembly, but he doesn't use instructions that are too different from our MIPS instructions
- Here's a quick little demo video I made of how to write Hello World in MIPS assembly: [Hello World i MIPS Assembly på (under) 5 minuter.](https://youtu.be/EGOCbQWv3s8?si=_REu7frV0ohdEWWk)
- Datasheet for all the standard MIPS instructions: [MIPS Reference Sheet](https://www.kth.se/social/files/563c63c9f276547044e8695f/mips-ref-sheet.pdf)

### What is the stack?

- This video by Low Level gives an introduction to the idea of the call stack. I'd recommend just watching the first 4 minutes, since his assembly example is in x86 assembly: [wtf is “the stack” ?](https://youtu.be/CRTR5ljBjPM?si=2Rnf8QGdosdiRSCT)
- *The stack grows backwards???* Watch this video by Low Level that goes through how to determine if that's true using a program written in C: [a strange but powerful interview question](https://youtu.be/V2h_hJ5MSpY?si=92qiITBbTMUG7oRA)

### Software

- Use the MIPS Assembler and Runtime Simulator (MARS) to test if your code works as intended. You can download it here: https://github.com/dpetersanderson/MARS/releases/tag/v.4.5.1

## 🏛 Assignments

### 15.1: Written answers

(You may write your answers in Swedish, all this is in English becasue I just started writing it in English without thinking about it and I couldn't be bothered to translate it all 😭💀)

**15.1.1**: Explain what the call stack is.  
**15.1.2**: In the regular task for this week, you are asked to implement a stack data structure in Java. In that implementation, each stack object stores a data variable and a pointer to another element. What is the equivalent of a stack object on the call stack, and how does it differ from the stack objects of the regular task?

### 15.2: Code tasks

**NOTE**: The stack pointer (register `sp`) in MARS starts at address `0x7fffeffc` (the "0x" notation denotes a hexadecimal (base 16) number), which is usually both the highest address of the stack and the bottom of the stack. We want `sp` to point to the lowest memory address in the stack instead. The stack in MARS is 4 MiB (2^20 bytes) large. Since each memory address can hold 4 bytes, we need to move `sp` down by 2^18 = 262144 = `0x4000`.

**TL;DR:** You'll need to start your program by subtracting `0x40000` from `sp` in order for the stack to start at its lowest memory address instead of its highest one.

**15.2.1:** Write the following C code in MIPS Assembly using a stack that grows up (remember, main is a function too! it also goes on the call stack)

```C
int main() {
    return 0;
}
```

**15.2.2:** Do the same for the following C code:

```C
int foo(int bar) {
    return bar*bar;
}

int main() {
    int four = foo(2);
    return 0;
}
```

**15.2.3 (Optional (GIGACHAD 🔥)):** Do the same for the following C code (this isn't as scary as it might look like at first):

```C
int a = 4;

void foo() {
    if (a > 0) {
        a--;
        foo();
    }
}

int main() {
    foo();
    return 0;
}
```

## TODOs:
- [ ] 15.1.1 Explain call stack
- [ ] 15.1.2 Compare stack from the regular task and the call stack
- [ ] 15.2.1 Compile C manually
- [ ] 15.2.2 Compile function in a function
- [ ] 15.2.3 Establish dominance

Remember, if you have any questions don't be afraid to send me a ping on Discord! You can also always do the regular task if I've been a little too evil this week with the difficulty of the plus task. Good luck!!! 😁
