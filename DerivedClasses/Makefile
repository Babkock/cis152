OPTS = -Wall -O2

all: DerivedClasses

DerivedClasses: main.o Clothing.o Shirt.o Pants.o
	g++ main.o Clothing.o Shirt.o Pants.o -o DerivedClasses
	strip DerivedClasses

main.o: main.cpp
	g++ ${OPTS} -c main.cpp

Clothing.o: Clothing.cpp
	g++ ${OPTS} -c Clothing.cpp

Shirt.o: Shirt.cpp
	g++ ${OPTS} -c Shirt.cpp

Pants.o: Pants.cpp
	g++ ${OPTS} -c Pants.cpp

clean:
	rm DerivedClasses main.o Clothing.o Shirt.o Pants.o

