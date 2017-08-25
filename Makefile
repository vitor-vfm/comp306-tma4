COMPILER=g++
FLAGS=-std=c++11 -g -Wall -Wpedantic

.PHONY: all q1 q2 q3

all: clean q1 q2 q3

q1:
	$(COMPILER) $(FLAGS) -o q1 TMA4Question1.cpp

q2:
	$(COMPILER) $(FLAGS) -o q2 TMA4Question2.cpp

q3:
	$(COMPILER) $(FLAGS) -o q3 TMA4Question3.cpp

clean:
	rm -rf q1 q2 q3
