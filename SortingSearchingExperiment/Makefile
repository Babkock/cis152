OPTS = -Wall -O2

all: sortingSearching

sortingSearching: linear.o binary.o bubble.o selection.o insertion.o sortingSearching.o
	g++ $^ -o $@
	strip $@

linear.o: linear.cpp
	g++ ${OPTS} -c $^ -o $@

binary.o: binary.cpp
	g++ ${OPTS} -c $^ -o $@

bubble.o: bubble.cpp
	g++ ${OPTS} -c $^ -o $@

selection.o: selection.cpp
	g++ ${OPTS} -c $^ -o $@

insertion.o: insertion.cpp
	g++ ${OPTS} -c $^ -o $@

sortingSearching.o: sortingSearching.cpp
	g++ ${OPTS} -c $^ -o $@

clean:
	rm sortingSearching linear.o binary.o bubble.o selection.o insertion.o sortingSearching.o
