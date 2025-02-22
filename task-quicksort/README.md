# ⏩Quicksort

This is the last assignment of DD1338!

It is obligatory for all students of the course, regardless of being in a plus group or not, to have implemented the quicksort algorithm.

Your assignment this week is therefore of course to implement the quicksort algorithm. On top of implementing the fundamental algorithm you also need to optimize it by using insertion sort for smaller arrays and picking a pivot element cleverly, or any other technique. 

To pass the assignment you need to have passed the Kattis assignment. (link below)

But since we're a ✨plus group✨, I heartily encourage you to make something more fun out of it. Try to get on some of the leaderboards! Quickest time across all languages is tough after all these years we've had this assignment, but there are leaderboards for more obscure languages too! (Yes I see you Prolog people... if you *really* are interested in going insane, it would seem as though nobody has managed to pass the assignment on Kattis with Prolog yet.)

## Instructions

1. Create a repository named `<KTH-ID>-quicksort` **(this time with the actual name of the assignment, not the number)**.
2. Clone your newly created repository and start coding.
3. Submit your solution to [Kattis](https://kth.kattis.com/courses/DD1338/algdat24). 

## Note on input

The Kattis assignment states that you should make a Java class who's function it's supposed to invoke. You plus students of course want to be able use other languages as well and have granular control over input so you can achieve maximum speed. For this it is still possible to read the input from stdin (input from command line) and output your answer to stdout (output into command line). The format Kattis follows for the assignment is as follows.

It begins with the number of elements to sort followed by every element, separated by spaces:
```
3 2 1 3
```
After sorting these elements you output them sorted on one line seperated by spaces:
```
1 2 3
```
