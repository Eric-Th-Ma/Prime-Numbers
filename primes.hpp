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
        Primes() = delete;
        Primes(size_t size);
        Primes(const Primes& orig);
        void swap(Primes& rhs);
        Primes& operator=(const Primes& rhs);
        ~Primes();

        size_t size() const;

        bool operator==(const Primes& rhs) const;
        bool operator!=(const Primes& rhs) const;

        using iterator = Iterator;
        iterator begin() const;  // An iterator that refers to the first element
        iterator end() const;

    private:
        int* primesList_;
        size_t size_;
        int* newPrimePtr_;

        class Iterator {
            public:
                // Definitions that are required for this class to be a well-behaved
                // STL-style iterator that moves forward through a collection of ints.
                using value_type = int;
                using reference = value_type&;
                using pointer = value_type*;
                using iterator_category = std::forward_iterator_tag;

                // Provide all the usual operations for a forward iterator

                Iterator() = default;
                Iterator(const Iterator&) = default;
                Iterator& operator=(const Iterator&) = default;
                ~Iterator() = default;

                Iterator& operator++();
                int& operator*() const;
                bool operator==(const Iterator& rhs) const;
                bool operator!=(const Iterator& rhs) const;
                int* operator->() const;
            private:
                friend class Primes;
                explicit Iterator(int* current);

                int* current_;
        };
};

// Provide a non-member version of swap to allow standard swap(x,y) usage.
void swap(Primes& lhs, Primes& rhs);

#endif  // PRIMES_HPP_INCLUDED