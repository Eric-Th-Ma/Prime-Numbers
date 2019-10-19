/*
 * \file main.cpp
 * \author Eric Thompson-Martin
 * \brief uses primes.cpp
 */

#include <iostream>
#include "primes.hpp"

int main() {
    Primes test{5000};
    std::cout << test.size() << std::endl;
    return 0;
}
