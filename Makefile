all: bst

# Symbols helpful for understanding the productions
#   $@ is the production's target
#   $^ are the production's prerequisites

bst:	bst.o		# trying to copy example
	cc -o $@ $^

bst.o:	bst.c bst.h    # trying to copy example
	cc -c bst.c

clean:
	rm -f *.o llDemo  bst

demo:   bst
	./bst
