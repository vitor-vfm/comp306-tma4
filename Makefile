COMPILER=g++
FLAGS=-std=c++11 -g

.PHONY: all q1

all: clean q1

q1:
	$(COMPILER) $(FLAGS) -o q1 TMA4Question1.cpp

clean:
	rm -rf q1
