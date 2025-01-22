#include "solution.hpp"

#include <map>
#include <unordered_map>

// TODO: Better use unordered_map here, but I had some compilation issues with it. Probably
// because of hash function missing. Previous results cached:
// - key: is a pair of size a, size b
// - value: is the calculation result
using Key = std::pair<int, int>;
using Map = std::map<Key, int>;

// Forward declare
static int lcs_with_memoization(Map& map, std::string_view a, std::string_view b);

// This function doesn't use map, but just passes it along to lcs_with_memoization. An alternative
// is to create a small class.
static int lcs_calculate(Map& map, std::string_view a, std::string_view b) {
    if (a.empty() || b.empty()) {
        return 0;
    }

    if (a[0] == b[0]) {
        return 1 + lcs(a.substr(1), b.substr(1));
    }

    return std::max(lcs_with_memoization(map, a.substr(1), b),
                    lcs_with_memoization(map, a, b.substr(1)));
}

// This function just checks if the calculation was already done for given strings. Returns cached
// value if available, delegates calculation to lcs_calculate otherwise (and caches the result).
static int lcs_with_memoization(Map& map, std::string_view a, std::string_view b) {
    auto key = Key(a.size(), b.size());

    auto found = map.find(key);
    if (found != map.end()) {
        return found->second;
    }

    int result = lcs_calculate(map, a, b);
    map[key] = result;
    return result;
}

// The top-level function, it simply creates a map and calls local functions for calculations. Not
// using static map, because we just store offsets as keys (not full strings), so static map would
// fail when this function would be called the second time during one execution, e.g. in tests.
int lcs(std::string_view a, std::string_view b) {
    Map map;
    return lcs_with_memoization(map, a, b);
}