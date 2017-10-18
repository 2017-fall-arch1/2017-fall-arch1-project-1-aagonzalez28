# arch1-linked-list-demo

This directory contains:
* code that implements a linked list of strings 
* a demo program that uses it

The demo program reads lines from stdin.
Each line is appended onto a linked list.
After end-of-file is read, the lines are printed out.

This demo contains the following files:
 bst.h: header file of llist structure & "public" interface functions
 bst.c: implementation of linked list
 

To compile:
~~~
$ make
~~~

To test it, try:
~~~
$ make demo
~~~

To delete binaries:
~~~
$ make clean
~~~

# Challenges #

 One of the main challenges was to learn how to use the poimters.
  - The syntax was confusing and sometimes it did not want to compile at all
  - It gave me a lot of errors and I had to go line by line to try to debug the program

Another challenge were the chars
  - C does not support string so I had to figure out how to implement them

  In my data structure class, they taught us how to crete a binary search tree in Java. So based on my Java codo,
I try to translate Java to C. In Java we had to create a file named BNode in which we implemented the linked list, then we
use inheritance to call that file to a main method in which we implemented the addNode, deleteNode, inOrder, preOrder, postOrder methods.
This helped me a lot to create this program. Ihad to go back to some of my old books to had them as reference. In the lab we discussed pointers,
and talked to some classmates about how to translate the code.


Sources:

	Gaddis, Tony. Starting out with Java: from Control Structures through Objects. 2nd ed., Pearson Education Limited, 2016.
	Sedgewick, Robert, and Kevin Wayne. Algorithms. 4th ed., Addison-Wesley, 2016.