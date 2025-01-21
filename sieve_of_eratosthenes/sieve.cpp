// Counts primes in the range from zero to the number supplied by user.
// Uses the sieve of Eratosthenes algorithm.
// Includes the optimization of starting from prime's square.
//
// Examples:
// sieve 0 -> 0
// sieve 5 -> 3
// sieve 30 -> 10
// sieve 1000000 -> 78498

#include <cmath>
#include <iostream>
#include <vector>

int count_primes(int n) {
  // This may be space-inefficient on some platforms. Normally bool takes one
  // byte, but std::vector<bool> should be optimized. 'std::vector<bool> is a
  // possibly space-efficient specialization' - notice the word 'possibly', the
  // memory optimization is implementation defined, but should be there on most
  // common platforms (I tested it on Ubuntu on x86-64 platform, it is
  // optimized).
  // An alternative would be std::bitset (but the issue is that size must be
  // known at compilation time) or simply a custom container.
  std::vector<bool> composites(n + 1, false);

  // Upper bound for marking composites
  int n_sqrt = std::ceil(std::sqrt(n));

  // Go through all numbers, start from 2 because 0 and 1 are neither primes nor
  // composites
  int count = 0;
  for (int i = 2; i <= n; ++i) {
    if (composites[i]) {
      // Is composite, not prime
      continue;
    }

    // Is prime, increment count
    ++count;

    // And mark all its multiplies as composites
    if (i < n_sqrt) {
      auto index = i * i;

      while (index <= n) {
        composites[index] = true;
        index += i;
      }
    }
  }

  return count;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cout << "Usage: " << argv[0] << " number\n";
    return 1;
  }

  int n = std::stoi(argv[1]);
  int result = count_primes(n);
  std::cout << "Primes count for numbers up to " << n << ": " << result << "\n";
  return 0;
}