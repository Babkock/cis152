OPTS = -Wall -O2

all: ListBasedStack

ListBasedStack: main.o stack.o stackemptyexception.o stackfullexception.o
	g++ main.o stack.o stackemptyexception.o stackfullexception.o -o ListBasedStack
	strip ListBasedStack

main.o: main.cpp
	g++ ${OPTS} -c main.cpp

stack.o: stack.cpp
	g++ ${OPTS} -c stack.cpp

stackemptyexception.o: stackemptyexception.cpp
	g++ ${OPTS} -c stackemptyexception.cpp

stackfullexception.o: stackfullexception.cpp
	g++ ${OPTS} -c stackfullexception.cpp

clean:
	rm ListBasedStack main.o stack.o stackemptyexception.o stackfullexception.o
