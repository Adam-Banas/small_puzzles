#include "solution.hpp"

// Basic LCS solution using recursion.
// This solution doesn't use memoization, so a lot of computations are repeated.
int lcs(std::string_view a, std::string_view b) {
    if (a.empty() || b.empty()) {
        return 0;
    }

    if (a[0] == b[0]) {
        return 1 + lcs(a.substr(1), b.substr(1));
    }

    return std::max(lcs(a.substr(1), b), lcs(a, b.substr(1)));
}