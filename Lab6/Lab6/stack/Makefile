COMPILER = gcc
CSTD = --std=c18
LIB = -lm
MAIN = ../../CI/objects/stack/stackM.o

stack: stack.o $(MAIN)
	$(COMPILER) $(CSTD) $(LIB) $(MAIN) stack.o -o stack

stack.o: stack.c stack.h 
	$(COMPILER) $(CSTD) $(LIB) -c stack.c

clean:
	rm -rf stack.o stack
