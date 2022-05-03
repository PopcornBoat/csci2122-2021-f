#
# makefile for array_list
# Yuxuan Wang
# B00880845
#

COMPILER = gcc
CSTD = --std=c18
LIBFLAGS = -lm
MAIN = ../../CI/objects/array_list/arrayM.o

array_list: array_list.o $(MAIN)
	$(COMPILER) $(CSTD) $(LIBFLAGS) $(MAIN) array_list.o -o array_list

array_list.o: array_list.c array_list.h 
	$(COMPILER) $(CSTD) $(LIBFLAGS) -c array_list.c

clean:
	rm -f array_list.o array_list
