#include <tuple>
#include <vector>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"
#include "../src/implementation.h"

TEST_CASE("testing the branch coverage reporting for paths within one line") {
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

TEST_CASE("testing the branch coverage reporting for paths nested across lines") {
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

TEST_CASE("testing the branch coverage reporting for switch paths") {
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

TEST_CASE("testing the json serialization of the default impluct") {
  impluct obj{};
  std::string expected = R"({"i":0,"hello":"","arr":[0,0,0],"map":{},"speckles":[]})";
  CHECK(to_json(obj) == expected);
}

TEST_CASE("testing the json serialization of a custom impluct") {
  impluct obj{
    .i=287,
    .hello{"Hello World"},
    .arr{1, 2, 3},
    .map{{"one", 1}, {"two", 2}},
    .speckles{
      {1, 1, 1, false},
      {0, 0, 0, true},
    },
  };
  std::string expected = R"({"i":287,"hello":"Hello World","arr":[1,2,3],"map":{"one":1,"two":2},"speckles":[[1,1,1,false],[0,0,0,true]]})";
  CHECK(to_json(obj) == expected);
}
