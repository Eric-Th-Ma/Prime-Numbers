/**
 * primes.hpp
 * A list of primes.
 */

#ifndef PRIMES_HPP_INCLUDED
#define PRIMES_HPP_INCLUDED

#include <cstddef>
#include <iostream>
#include <utility>

/**
 * Primes
 * 
 * A heap array of size primes
 */

class Primes {
    private:
        class Iterator;
    
    public:
        // Constructs a Primes object with size primes
        Primes(size_t size);
        // Default constructs an empty Primes object
        Primes();
        Primes(const Primes& orig);
        void swap(Primes& rhs);
        Primes& operator=(const Primes& rhs);
        ~Primes();

        // Quick access to the number of primes stored
        size_t size() const;

        int checkPrime(int testPrime) const;

        bool operator==(const Primes& rhs) const;
        bool operator!=(const Primes& rhs) const;

        using iterator = Iterator;
        iterator begin() const;  // An iterator that refers to the first element
        iterator end() const;  // An iterator one past the end 

    private:
        size_t size_;
        int* primesList_;
        int* newPrimePtr_;

        class Iterator {
            public:
                // Definitions that are required for this class to be a well-behaved
                // STL-style iterator that moves forward through a collection of ints.
                using value_type = int;
                using reference = value_type&;
                using pointer = value_type*;
                using iterator_category = std::random_access_iterator_tag;

                // All the usual operations for a forward iterator

                Iterator() = default;
                Iterator(const Iterator&) = default;
                Iterator& operator=(const Iterator&) = default;
                ~Iterator() = default;

                Iterator& operator++();
                Iterator& operator--();
                Iterator operator+(const int& rhs);
                Iterator operator-(const int& rhs);
                value_type& operator[](const int& rhs);
                value_type& operator*() const;
                bool operator==(const Iterator& rhs) const;
                bool operator!=(const Iterator& rhs) const;
                value_type* operator->() const;
            private:
                friend class Primes;
                explicit Iterator(int* current);

                int* current_;
        };
};

// Provide a non-member version of swap to allow standard swap(x,y) usage.
void swap(Primes& lhs, Primes& rhs);

#endif  // PRIMES_HPP_INCLUDED