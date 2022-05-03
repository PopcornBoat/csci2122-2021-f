COMPILER = gcc
CSTD = --std=c18 
LIB = -lm
INCLUDE = -I lib
OBJ = stack.o queue.o linked_list.o
MAIN = ../../CI/objects/search/searchM.o
DFS = ../../CI/objects/search/dfsM.o
BFS = ../../CI/objects/search/bfsM.o

all: search dfs bfs

search: search.o $(MAIN) $(OBJ)
	$(COMPILER) $(CSTD) $(LIB) $(MAIN) $(OBJ) search.o -o search

dfs: search.o $(DFS) $(OBJ)
	$(COMPILER) $(CSTD) $(LIB) $(DFS) $(OBJ) search.o -o dfs
	
bfs: search.o $(BFS) $(OBJ)
	$(COMPILER) $(CSTD) $(LIB) $(BFS) $(OBJ) search.o -o bfs

search.o: bintree.c bintree.h
	$(COMPILER) $(CSTD) $(LIB) $(INCLUDE) -c bintree.c -o search.o

stack.o: lib/stack.c lib/stack.h
	$(COMPILER) $(CSTD) $(LIB) $(INCLUDE) -c lib/stack.c
	
queue.o: lib/queue.c lib/queue.h
	$(COMPILER) $(CSTD) $(LIB) $(INCLUDE) -c lib/queue.c

linked_list.o : lib/linked_list.c lib/linked_list.h
	$(COMPILER) $(CSTD) $(LIB) $(INCLUDE) -c lib/linked_list.c -o linked_list.o

clean:
	rm -f search search.o
	rm -f dfs bfs
	rm -f stack.o queue.o linked_list.o

