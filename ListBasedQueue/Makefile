OPTS = -Wall -O2

all: ListBasedQueue

ListBasedQueue: main.o queue.o queueemptyexception.o queuefullexception.o
	g++ main.o queue.o queueemptyexception.o queuefullexception.o -o ListBasedQueue
	strip ListBasedQueue

main.o: main.cpp
	g++ ${OPTS} -c main.cpp

queue.o: queue.cpp
	g++ ${OPTS} -c queue.cpp

queueemptyexception.o: queueemptyexception.cpp
	g++ ${OPTS} -c queueemptyexception.cpp

queuefullexception.o: queuefullexception.cpp
	g++ ${OPTS} -c queuefullexception.cpp

clean:
	rm ListBasedQueue main.o queue.o queueemptyexception.o queuefullexception.o
