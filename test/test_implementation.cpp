#include <tuple>
#include <vector>

#include <doctest/doctest.h>
#include <spdlog/spdlog.h>
#include <yaml-cpp/yaml.h>

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
    {1, 9},
    {2, 9},
    {3, 9},
    {4, 9},
    {5, 9},
    {6, 9},
    {7, 9},
    {8, 9},
    {9, 9},
    {10, 42},
    {11, 42},
    {12, 42},
    {13, 42},
    {14, 42},
    {15, 42},
    {16, 42},
    {17, 42},
    {18, 42},
    {19, 42},
    {20, 42},
    {21, 42},
    {22, 44},
  };
  for (const auto tuplet: tuplets) {
    const auto [a, expected] = tuplet;
    CHECK(switch_logic(a) == expected);
  }
}

TEST_CASE("testing the json dump of the default impluct") {
  impluct obj{};
  std::string expected = R"({"i":0,"hello":"","arr":[0,0,0],"map":{},"speckles":[]})";
  CHECK(to_json(obj) == expected);
}

TEST_CASE("testing the json dump of a custom impluct") {
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

TEST_CASE("testing the json load yields the default impluct on default successful and failed json parse") {
  std::vector<std::string> buffers{
    {R"({"i":0,"hello":"","arr":[0,0,0],"map":{},"speckles":[]})"},
    {R"({"invalid-values":true})"},
  };
  std::vector<spdlog::level::level_enum> levels{spdlog::level::debug, spdlog::level::critical};
  for (auto buffer: buffers) {
    for (auto level: levels) {
      spdlog::set_level(level);
      impluct empty{};
      INFO(R"({"i":0,"hello":"","arr":[0,0,0],"map":{},"speckles":[]})");
      impluct obj = impluct_from_json(buffer);
      CHECK(obj.i == empty.i);
      CHECK(obj.hello == empty.hello);
      CHECK(obj.arr == empty.arr);
      CHECK(obj.map == empty.map);
      CHECK(obj.speckles == empty.speckles);
    }
  }
}

TEST_CASE("testing the json load of a custom json yields an object equal to equivalend constructor") {
  impluct equivalent{
    .i=287,
    .hello{"Hello World"},
    .arr{1, 2, 3},
    .map{{"one", 1}, {"two", 2}},
    .speckles{
      {1, 1, 1, false},
      {0, 0, 0, true},
    },
  };
  std::string buffer = R"({"i":287,"hello":"Hello World","arr":[1,2,3],"map":{"one":1,"two":2},"speckles":[[1,1,1,false],[0,0,0,true]]})";
  impluct obj = impluct_from_json(buffer);
  CHECK(obj.i == equivalent.i);
  CHECK(obj.hello == equivalent.hello);
  CHECK(obj.arr == equivalent.arr);
  CHECK(obj.map == equivalent.map);
  CHECK(obj.speckles == equivalent.speckles);
}

TEST_CASE("testing confluct load from yaml") {
  std::string buffer = R"(---
  i: 287
  hello: Hello World
  arr:
    - 1
    - 2
    - 3
  map:
    one: 1
    two: 2
  )";
  auto config = confluct_from_yaml(buffer);
  CHECK(config.i == 287);
  CHECK(config.hello == std::string{"Hello World"});
  CHECK(config.arr == std::array<uint64_t, 3>{1, 2, 3});
  CHECK(config.map == std::map<std::string, int>{{"one", 1}, {"two", 2}});
}

TEST_CASE("testing confluct load from json") {
  std::string buffer = R"({"i":287,"hello":"Hello World","arr":[1,2,3],"map":{"one":1,"two":2}})";
  auto config = confluct_from_json(buffer);
  CHECK(config.i == 287);
  CHECK(config.hello == std::string{"Hello World"});
  CHECK(config.arr == std::array<uint64_t, 3>{1, 2, 3});
  CHECK(config.map == std::map<std::string, int>{{"one", 1}, {"two", 2}});
}

TEST_CASE("testing failing confluct load from json") {
  confluct empty{};
  std::string buffer = R"({"invalid-values":true})";
  auto config = confluct_from_json(buffer);
  CHECK(config.i == empty.i);
  CHECK(config.hello == empty.hello);
  CHECK(config.arr == empty.arr);
  CHECK(config.map == empty.map);
}

TEST_CASE("testing confluct dump to yaml") {
  confluct config{
    .i=287,
    .hello{"Hello World"},
    .arr{1, 2, 3},
    .map{{"one", 1}, {"two", 2}},
  };
  std::string expected = R"(i: 287
hello: Hello World
arr:
  - 1
  - 2
  - 3
map:
  one: 1
  two: 2)";
  auto yaml_dumped = to_yaml(config);
  CHECK(yaml_dumped == expected);
}
