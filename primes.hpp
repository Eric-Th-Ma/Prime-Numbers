/**
 * primes.hpp
 * A list of primes.
 */

#ifndef PRIMES_HPP_INCLUDED
#define PRIMES_HPP_INCLUDED

#endif  // PRIMES_HPP_INCLUDED

/**
 * Primes
 * 
 * A heap array of n primes
 */

class Primes {
    private:
        class Iterator;
    
    public:
        Primes() = delete;
        Primes(const Primes& orig);
        Primes& operator=(const Primes& rhs);
        ~Primes();
        Primes(size_t size);

        size_t size() const;

        bool operator==(const IntList& rhs) const;
        bool operator!=(const IntList& rhs) const;

        using iterator = Iterator;
        iterator begin() const;  // An iterator that refers to the first element
        iterator end() const;
    private:
        int* primesList_;
        size_t size_;

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