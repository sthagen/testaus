#include <tuple>
#include <vector>

#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include "../src/implementation.h"

TEST_CASE("testing the branch coverage reporting for paths within one line via Catch2") {
    std::vector<std::tuple<int, int, int, int>> tuplets = {
        // a, b, c, expected
        {1, 0, 0, 1},
        {0, 1, 0, 1},
        {1, 0, 1, 1},
        {0, 0, 0, 0},
    };
    for (const auto tuplet: tuplets) {
        const auto [a, b, c, expected] = tuplet;
        CHECK(triple_max(a, b, c) == expected);
    }
}

TEST_CASE("testing the branch coverage reporting for paths nested across lines via Catch2") {
    std::vector<std::tuple<int, int>> tuplets = {
        // a, expected
        {0, 42},
        {1, 42},
        {21, 42},
        {22, 44},
    };
    for (const auto tuplet: tuplets) {
        const auto [a, expected] = tuplet;
        CHECK(spread_logic(a) == expected);
    }
}

TEST_CASE("testing the branch coverage reporting for switch paths via Catch2") {
    std::vector<std::tuple<int, int>> tuplets = {
        // a, expected
        {0, 42},
        {1, 42},
        {21, 42},
        {22, 44},
    };
    for (const auto tuplet: tuplets) {
        const auto [a, expected] = tuplet;
        CHECK(switch_logic(a) == expected);
    }
}

