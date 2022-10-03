#!/bin/sh
g++ -c main.cpp -O2 -Wall -o main.o
g++ -c queue.cpp -O2 -Wall -o queue.o
g++ -c queuefullexception.cpp -O2 -Wall -o queuefullexception.o
g++ -c queueemptyexception.cpp -O2 -Wall -o queueemptyexception.o
g++ main.o queue.o queuefullexception.o queueemptyexception.o -o ListBasedQueue
strip ListBasedQueue

