CPL = g++
VWALL = -Wall -std=c++11

all:
	$(CPL) $(VWALL) *.cpp -o main

clean:
	rm -f main