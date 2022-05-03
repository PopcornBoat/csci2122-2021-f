#
# makefile for linked_list
# Yuxuan Wang
# B00880845
#


COMPILER = gcc
CSTD = --std=c18
LIBFLAGS = -lm
MAIN = ../../CI/objects/linked_list/linkedM.o

linked_list: linked_list.o $(MAIN)
	$(COMPILER) $(CSTD) $(LIBFLAGS) $(MAIN) linked_list.o -o linked_list

linked_list.o: linked_list.c linked_list.h 
	$(COMPILER) $(CSTD) $(LIBFLAGS) -c linked_list.c

clean:
	rm -f linked_list.o linked_list

