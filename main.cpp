/*
 * \file main.cpp
 * \author Eric Thompson-Martin
 * \brief uses primes.cpp
 */

#include <iostream>
#include <fstream>
#include <list>
#include "primes.hpp"

int main() {
    Primes test{30};
    Primes::iterator it = test.end();
    int biggest = it[-1];
    std::ofstream outputFile;
    outputFile.open ("Prime-Factorization.csv");
    outputFile << ",n,Number of prime factors,Prime factors of n,\n";
    for (size_t i = 2; i <= static_cast<size_t>((biggest + 1) * (biggest + 1) - 1); ++i) {
        outputFile << "," << i << ",";
        std::list<int> factors = test.factorize(i);
        outputFile << factors.size() << ",";
        while (factors.size() > 0) {
            outputFile << factors.front() << ",";
            factors.pop_front();
        }
        outputFile << "\n";
    }
    outputFile.close();
    // int numPrimes;
    // std::cout << "Length: ";
    // std::cin >> numPrimes;
    // Primes testTwo{static_cast<size_t>(numPrimes)};
    // Primes test = testTwo;
    // Primes::iterator it = test.begin();
    // std::cout << "Prime number: ";
    // int primeNum;
    // std::cin >> primeNum;
    // std::cout << "Is: " << it[primeNum-1] << std::endl;
    // std::cout << "Check prime: ";
    // int checkPrimeNum;
    // std::cin >> checkPrimeNum;
    // std::cout << "Is: " << test.checkPrime(checkPrimeNum) << std::endl;
    return 0;
}
