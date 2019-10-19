/*
 * \file primes.cpp
 * \author Eric Thompson-Martin
 * \brief Implimentation of Primes
 */

Primes::Primes(size_t size) : size_(size), primesList_(new int[size]) {
    // TODO: make list of size primes
}

Primes::Primes(const Primes& orig) : size_(orig.size()), primesList_(new int[orig.size()]) {
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

  affirm(consistent());
  return *this;
}

Primes::~Primes() {
    // deletes the array on the heap
    delete primesList_;
}

size_t Primes::size() const {
    return size_;
}

bool Primes::operator==(const Primes& rhs) const {
    // TODO: check all values are equal
    return true;
}

bool Primes::operator!=(const Primes& rhs) const {
    return !(this==rhs);
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

int& Primes::Iterator::operator*() {
    return (*current_);
}

bool Primes::Iterator::operator==(const Iterator& rhs) const {
    return (current_ == rhs.current_);
}

bool Primes::Iterator::operator!=(const Iterator& rhs) const {
  // Idiomatic code: leverage == to implement !=
  return !(*this == rhs);
}

int* IntList::Iterator::operator->() const {
  return &(*current_);
}
