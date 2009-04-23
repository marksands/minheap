
all: heap

heap: main.o
	g++ main.o -o heap

main.o: main.cc
	g++ -c main.cc

clean:
	rm -rf *o heap
	
