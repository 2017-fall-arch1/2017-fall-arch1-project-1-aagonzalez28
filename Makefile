all: llDemo bst

CFLAGS=-g -O3 -Wall

# Symbols helpful for understanding the productions
#   $@ is the production's target
#   $^ are the production's prerequisites

bst:	bst.o		# trying to copy example
	cc -o $@ $^

llDemo: llist.o llDemo.o
	cc -o $@ $^

bst.o:	bst.c bst.h    # trying to copy example
	cc -c $(CFLAGS) bst.c

llist.o: llist.c llist.h
	cc -c $(CFLAGS) llist.c

llDemo.o: llDemo.c llist.h
	cc -c $(CFLAGS) llDemo.c

clean:
	rm -f *.o llDemo  bst

demo: llDemo bst
	(echo first; echo "second line"; echo "third and last") | ./llDemo ./bst

#missing some variables 

