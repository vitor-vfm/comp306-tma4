COMPILER=g++
FLAGS=-std=c++11 -g -Wall -Wpedantic

.PHONY: all q1 q2

all: clean q1 q2

q1:
	$(COMPILER) $(FLAGS) -o q1 TMA4Question1.cpp

q2:
	$(COMPILER) $(FLAGS) -o q2 TMA4Question2.cpp

clean:
	rm -rf q1 q2
