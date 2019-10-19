/*
 * \file main.cpp
 * \author Eric Thompson-Martin
 * \brief uses primes.cpp
 */

#include <iostream>
#include "primes.hpp"

int main() {
    int numPrimes;
    std::cout << "Length: ";
    std::cin >> numPrimes;
    Primes testTwo{static_cast<size_t>(numPrimes)};
    Primes test = testTwo;
    Primes::iterator it = test.begin();
    std::cout << "Prime number: ";
    int primeNum;
    std::cin >> primeNum;
    std::cout << "Is: " << it[primeNum] << std::endl;
    return 0;
}
