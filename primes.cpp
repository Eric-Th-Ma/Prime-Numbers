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
        // So it is very unlikely for it to be under nxlog2(n)
        // Additionally log2 is much cheaper than log10
        int testUnder = size*(std::log2(size)+1);
        std::list<int> testList;
        // std::cout << testList.max_size() << std::endl;
        for (size_t i = 3; i <= testUnder; i+=2) {
            testList.push_back(i);
        }
        primesList_[0] = 2;
        ++size_;
        while (size_<size) {
            *newPrimePtr_ = testList.front();
            testList.pop_front();
            testList.remove_if([this](int n){return n % *this->newPrimePtr_ == 0;});
            primesList_[size_] = *newPrimePtr_;
            std::cout << *newPrimePtr_ << std::endl;
            ++size_;
        }
    }
}

Primes::Primes(const Primes& orig) : size_(orig.size()), primesList_(new int[orig.size()]), newPrimePtr_(new int) {
    // TODO: copy values from orig into new Primes
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
    // deletes the array on the heap
    delete[] primesList_;
    delete newPrimePtr_;
}

size_t Primes::size() const {
    return size_;
}

bool Primes::operator==(const Primes& rhs) const {
    // TODO: check all values are equal
    return true;
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
    // TODO:: increment
    ++current_;
    return (*this);
}

int& Primes::Iterator::operator*() const {
    return (*current_);
}

bool Primes::Iterator::operator==(const Iterator& rhs) const {
    return (current_ == rhs.current_);
}

bool Primes::Iterator::operator!=(const Iterator& rhs) const {
  // Idiomatic code: leverage == to implement !=
  return !(*this == rhs);
}

int* Primes::Iterator::operator->() const {
  return &(*current_);
}
