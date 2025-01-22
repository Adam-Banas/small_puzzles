cmake_minimum_required(VERSION 3.14)
project(lcs)

# Set standard to C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Subdirectories with solution and test
add_subdirectory(solution)
add_subdirectory(tests)

# Main executable for manual testing
add_executable(lcs main.cpp)
target_link_libraries(
    lcs
    PRIVATE lcs_solution
)