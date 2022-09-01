#!/bin/sh
g++ -c main.cpp -O2 -Wall -o main.o
g++ -c Clothing.cpp -O2 -Wall -o Clothing.o
g++ -c Pants.cpp -O2 -Wall -o Pants.o
g++ -c Shirt.cpp -O2 -Wall -o Shirt.o
g++ main.o Clothing.o Pants.o Shirt.o -o DerivedClasses
strip DerivedClasses

