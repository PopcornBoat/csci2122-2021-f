COMPILER = gcc
CSTD = --std=c18
LIB = -lm
BINM = ../../CI/objects/bintree/bintreeM.o
INORDER = ../../CI/objects/bintree/intreeM.o
PREORDER = ../../CI/objects/bintree/pretreeM.o
POSTORDER = ../../CI/objects/bintree/posttreeM.o
REVORDER = ../../CI/objects/bintree/revtreeM.o

COMPILE = $(COMPILER) $(CSTD) $(LIB)

all: bintree.o $(BINM) $(INORDER) $(PREORDER) $(POSTORDER) $(REVORDER)
	make bintree intree pretree posttree revtree

bintree: bintree.o $(BINM)
	$(COMPILE) $(BINM) bintree.o -o bintree

intree: bintree.o $(INORDER)
	$(COMPILE) $(INORDER) bintree.o -o intree
	
pretree: bintree.o $(PREORDER)
	$(COMPILE) $(PREORDER) bintree.o -o pretree
	
posttree: bintree.o $(POSTORDER)
	$(COMPILE) $(POSTORDER) bintree.o -o posttree
	
revtree: bintree.o $(REVORDER)
	$(COMPILE) $(REVORDER) bintree.o -o revtree

bintree.o: bintree.c bintree.h
	$(COMPILE) -c bintree.c

clean:
	rm -rf bintree.o bintree intree pretree posttree revtree

