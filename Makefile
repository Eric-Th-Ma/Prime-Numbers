CXX = clang++
CXX_FlAG = -g -std=c++1z -Wall -Wextra -pedantic

all: main

main: main.o primes.o
	$(CXX) $(CXX_FlAG) -o main main.o primes.o

main.o: main.cpp primes.hpp
	$(CXX) $(CXX_FlAG) -c main.cpp

primes.o: primes.cpp primes.hpp
	$(CXX) $(CXX_FlAG) -c primes.cpp

clean:
	rm -rf main *.o