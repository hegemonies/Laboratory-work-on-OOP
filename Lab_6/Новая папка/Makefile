all: main

main: main.o
	g++ -std=c++11 -Wall main.o -o main

main.o: main.cpp
	g++ -std=c++11 -Wall -c main.cpp -o main.o

vector.o: vector.cpp
	g++ -std=c++11 -Wall -c vector.cpp -o vector.o

.PHONY: clean

clean:
	rm main main.o vector.o