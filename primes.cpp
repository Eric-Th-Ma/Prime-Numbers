/*
 * \file primes.cpp
 * \author Eric Thompson-Martin
 * \brief Implimentation of Primes
 */

#include <utility>
#include "primes.hpp"
#include <list>
#include <iostream>
#include <cmath>

Primes::Primes(size_t size) : size_(0), primesList_(new int[size]), newPrimePtr_(new int) {
    if (size>0) {
        // The nth prime is approximately nxlog10(n)
        // So it is very unlikely (maybe even impossible
        // for it to be under nx(log2(n) + 1)
        // Additionally log2 is much cheaper than log10
        size_t testUnder = size*(std::log2(size)+1);
        std::list<int> testList;
        /* Test code:
            std::cout << "Under: " << testUnder << std::endl;
            std::cout << testList.max_size() << std::endl;
         */
        // Make a list of the numbers to test
        for (size_t i = 3; i <= testUnder; i+=2) {
            testList.push_back(i);
        }
        // Add two to primes
        primesList_[0] = 2;
        ++size_;
        while (size_<size) {
            // Add the first test prime to primes and remove it from the test list
            *newPrimePtr_ = testList.front();
            testList.pop_front();
            // Remove every multiple of this new prime from the test list
            testList.remove_if([this](int n){return n % *this->newPrimePtr_ == 0;});
            primesList_[size_] = *newPrimePtr_;
            // std::cout << "p = " << *newPrimePtr_ << std::endl;
            ++size_;
        }
    }
}

Primes::Primes() : size_(0), primesList_(new int[0]), newPrimePtr_(new int) {
    // Nothing else to do.
    // Default Primes is empty
}

Primes::Primes(const Primes& orig) : size_(orig.size()), primesList_(new int[orig.size()]), newPrimePtr_(new int) {
    iterator origIt = orig.begin();
    for (size_t i = 0; i < size_; ++i) {
        primesList_[i] = origIt[i];
    }
}

void Primes::swap(Primes& rhs) {
    // This is the canonical way to swap arbitrary types; this incantation
    // will call std::swap unless we're swapping a class that provides its
    // own swap function (like we do), in which case that swap is called.
    // Here we end up calling std::swap since the swapped parts are primitives.

    using std::swap;

    swap(primesList_, rhs.primesList_);
    swap(size_, rhs.size_);
}

void swap(Primes& lhs, Primes& rhs) { lhs.swap(rhs); }

Primes& Primes::operator=(const Primes& rhs) {
    // Assignment is implemented idiomatically for C++, using "the swap trick"
    Primes copy = rhs;
    swap(copy);

    return *this;
}

Primes::~Primes() {
    // deletes the array on the heap and single int on the heap
    delete[] primesList_;
    delete newPrimePtr_;
}

size_t Primes::size() const {
    return size_;
}

int Primes::checkPrime(int testPrime) const {
    int maxPrime = primesList_[size_-1];
    if (testPrime > (maxPrime * maxPrime)) {
        std::cout << "Testing too large. Up size of primes, or test smaller." << std::endl;
        return 0;
    } else {
        for (size_t i = 0; i < size_; ++i) {
            if (testPrime == primesList_[i]) {
                return (i + 1);
            } else if ((testPrime % primesList_[i]) == 0) {
                return 0;
            }
        }
        std::cout << "To large to know which one but yes it is a prime." << std::endl;
        return (size_ + 1);
    }
}

bool Primes::operator==(const Primes& rhs) const {
    if (size_ != rhs.size()) {
        return false;
    } else {
        iterator rhsIt = rhs.begin();
        for (size_t i = 0; i < size_; ++i) {
            if (primesList_[i] != rhsIt[i]) {
                return false;
            }
        }
        return true;
    }
}

bool Primes::operator!=(const Primes& rhs) const {
    return !(*this==rhs);
}

Primes::iterator Primes::begin() const {
    return Iterator{primesList_};
}

Primes::iterator Primes::end() const {
    return Iterator{primesList_ + size_};
}

// --------------------------------------
// Implementation of Primes::Iterator
// --------------------------------------

Primes::Iterator::Iterator(int* current) : current_(current) {
    // Nothing else to do.
}

Primes::Iterator& Primes::Iterator::operator++() {
    ++current_;
    return (*this);
}

Primes::Iterator& Primes::Iterator::operator--() {
    --current_;
    return (*this);
}

Primes::Iterator Primes::Iterator::operator+(const int& rhs) {
    int* ptr = current_ + rhs;
    return Iterator{ptr};
}

Primes::Iterator Primes::Iterator::operator-(const int& rhs) {
    int* ptr = current_ - rhs;
    return Iterator{ptr};
}

int Primes::Iterator::operator[](const int& rhs) {
    return current_[rhs];
}

int Primes::Iterator::operator*() const {
    return (*current_);
}

bool Primes::Iterator::operator==(const Iterator& rhs) const {
    return (current_ == rhs.current_);
}

bool Primes::Iterator::operator!=(const Iterator& rhs) const {
    // Idiomatic code: leverage == to implement !=
    return !(*this == rhs);
}
/*
 int* Primes::Iterator::operator->() const {
    return &(*current_);
 }
 */
