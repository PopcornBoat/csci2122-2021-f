COMPILER = gcc
CSTD = --std=c18
LIB = -lm
MAIN = ../../CI/objects/queue/queueM.o

queue: queue.o $(MAIN)
	$(COMPILER) $(CSTD) $(LIB) $(MAIN) queue.o -o queue

queue.o: queue.c queue.h 
	$(COMPILER) $(CSTD) $(LIB) -c queue.c

clean:
	rm -rf queue.o queue

