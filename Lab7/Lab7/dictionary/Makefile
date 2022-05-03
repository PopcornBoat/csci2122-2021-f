COMPILER = gcc
CSTD = --std=c18
LIB = -lm
INCLUDE = -I lib -I ../search -I ../search/lib
OBJ = array_list.o bintree.o queue.o stack.o linked_list.o
MAIN = ../../CI/objects/search/searchM.o


dictionary: dictionary.o $(MAIN) $(OBJ)
	$(COMPILER) $(CSTD) $(LIB) $(MAIN) $(OBJ) dictionary.o -o dictionary

dictionary.o: dictionary.c dictionary.h
	$(COMPILER) $(CSTD) $(LIB) $(INCLUDE) -c dictionary.c

array_list.o: lib/array_list.c lib/array_list.h
	$(COMPILER) $(CSTD) $(LIB) $(INCLUDE) -c lib/array_list.c
	
bintree.o: ../search/bintree.c ../search/bintree.h
	$(COMPILER) $(CSTD) $(LIB) $(INCLUDE) -c ../search/bintree.c
	
queue.o: ../search/lib/queue.c ../search/lib/queue.h
	$(COMPILER) $(CSTD) $(LIB) $(INCLUDE) -c ../search/lib/queue.c

stack.o: ../search/lib/stack.c ../search/lib/stack.h
	$(COMPILER) $(CSTD) $(LIB) $(INCLUDE) -c ../search/lib/stack.c

linked_list.o: ../search/lib/linked_list.c ../search/lib/linked_list.h
	$(COMPILER) $(CSTD) $(LIB) $(INCLUDE) -c ../search/lib/linked_list.c


clean:
	rm -rf dictionary dictionary.o
	rm -rf array_list.o bintree.o
	rm -rf queue.o stack.o linked_list.o
