# Fetch GoogleTest library and prepare it for use
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        b514bdc898e2951020cbdca1304b75f5950d1f59 # release-1.15.2
)
FetchContent_MakeAvailable(googletest)

# Add tests executable, link with googletest
enable_testing()
add_executable(
  lcs_tests
  tests.cpp
)
target_link_libraries(
    lcs_tests
    PRIVATE GTest::gtest_main
            lcs_solution
)

# Enable CMake's test runner to discover the tests
# (usage, when built: cd tests && ctest)
include(GoogleTest)
gtest_discover_tests(lcs_tests)