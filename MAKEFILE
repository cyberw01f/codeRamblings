CC = g++

all: problem1 problem2 problem3

problem1: problem1.cpp
	$(CC) -std=c++11 -o problem1 problem1.cpp

problem2: problem2.cpp
	$(CC) -std=c++11 -o problem2 problem2.cpp

problem3: problem3.cpp
	$(CC) -std=c++11 -o problem3 problem3.cpp

clean:
	rm -f *.o problem1 problem2 problem3
