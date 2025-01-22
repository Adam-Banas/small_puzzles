#include <iostream>

#include "solution/solution.hpp"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cout << "Add two integers\n";
        std::cout << "Usage: " << argv[0] << " x y\n";
        return 1;
    }

    int x = std::stoi(argv[1]);
    int y = std::stoi(argv[2]);

    int result = add(x, y);
    std::cout << x << " + " << y << " = " << result << "\n";
    return 0;
}