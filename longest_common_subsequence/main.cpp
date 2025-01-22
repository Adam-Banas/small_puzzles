#include <iostream>

#include "solution/solution.hpp"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cout << "Find the longest common subsequence of two strings.\n";
        std::cout << "Usage: " << argv[0] << " string1 string2\n";
        return 1;
    }

    std::string a = argv[1];
    std::string b = argv[2];

    int result = lcs(a, b);
    std::cout << "Length of LCS for " << a << " and " << b << " is: " << result << "\n";
    return 0;
}