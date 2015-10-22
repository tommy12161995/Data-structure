Introduce:
It is program that two rats in the maze and both of them want to walk to end.

Bug fixed:
1.At first,I only use one maze to save path, but I can't save path of them.
So,I use three maze.one is a real maze,the other is saving path of ratA,
another is saving path of ratB.

2.I forgot to check which floor the rat stay.

Implementation:
I set two stacks.one is save (z,x,y) of ratA,the other is save (z,x,y) of ratB.
rat A and B walk maze in the loop and save (z,x,y) in the stack.and if no way 
let rats walk,they will go back by saving of stack.

Compilation:
Using gcc -std=c99 -o a.out main.c

