COMPILER = gcc
CSTD = --std=c18
LIB = -lm
INCLUDE = -I lib
MYLIB = array_list.o
HEAP = ../../CI/objects/heap/heapM.o
reHEAP = ../../CI/objects/heap/rheapM.o

all: heap rheap

heap: heap.o $(HEAP) $(MYLIB)
	$(COMPILER) $(CSTD) $(LIB) $(HEAP) $(MYLIB) heap.o -o heap
	
rheap: heap.o $(reHEAP) $(MYLIB)
	$(COMPILER) $(CSTD) $(LIB) $(reHEAP) $(MYLIB) heap.o -o rheap
	
heap.o: heap.c heap.h
	$(COMPILER) $(CSTD) $(LIB) $(INCLUDE) -c heap.c

array_list.o: lib/array_list.c lib/array_list.h
	$(COMPILER) $(CSTD) $(LIB) $(INCLUDE) -c lib/array_list.c

clean:
	rm -f heap rheap heap.o
	rm -f array_list.o
