#include<string>
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
  };
  for (int i=1; i <10; ++i) tuplets.push_back({i, 9});
  for (int i=10; i <22; ++i) tuplets.push_back({i, 42});
  tuplets.push_back({22, 44});

  for (const auto tuplet: tuplets) {
    const auto [a, expected] = tuplet;
    CHECK(switch_logic(a) == expected);
  }
}

TEST_CASE("testing the json dump of the default impluct") {
  impluct obj{};
  std::string expected =
    R"({"j":0,"bye":"","triplet":[0,0,0],"dict":{},"config":{"i":0,"hello":"","arr":[0,0,0],"map":{}}})";
  CHECK(to_json(obj) == expected);
}

TEST_CASE("testing the json dump of a custom impluct") {
  impluct obj{
    .j=287,
    .bye{"Hello World"},
    .triplet{1, 2, 3},
    .dict{{"one", 1}, {"two", 2}},
    .config{
      .i=42,
      .hello{"Yes"},
      .arr{0, 0, 0},
      .map{{"verbose", 0}},
    },
  };
  std::string expected =
    R"({"j":287,"bye":"Hello World","triplet":[1,2,3],"dict":{"one":1,"two":2},)"
    R"("config":{"i":42,"hello":"Yes","arr":[0,0,0],"map":{"verbose":0}}})";
  CHECK(to_json(obj) == expected);
}

TEST_CASE("testing the json load yields the default impluct on default successful and failed json parse") {
  std::vector<std::string> buffers{
    {R"({"j":0,"bye":"","triplet":[0,0,0],"dict":{},"config":{"i":0,"hello":"","arr":[0,0,0],"map":{}}})"},
    {R"({"invalid-values":true})"},
  };
  std::vector<spdlog::level::level_enum> levels{spdlog::level::debug, spdlog::level::critical};
  for (auto buffer: buffers) {
    for (auto level: levels) {
      spdlog::set_level(level);
      impluct empty{};
      INFO(R"({"j":0,"bye":"","triplet":[0,0,0],"dict":{},"config":{"i":0,"hello":"","arr":[0,0,0],"map":{}}})");
      impluct obj = impluct_from_json(buffer);
      CHECK(obj.j == empty.j);
      CHECK(obj.bye == empty.bye);
      CHECK(obj.triplet == empty.triplet);
      CHECK(obj.dict == empty.dict);
      CHECK(obj.config.i== empty.config.i);
    }
  }
}

TEST_CASE("testing the json load of a custom json yields an object equal to equivalend constructor") {
  impluct equivalent{
    .j=287,
    .bye{"Hello World"},
    .triplet{1, 2, 3},
    .dict{{"one", 1}, {"two", 2}},
    .config{
      .i=1,
      .hello{"No"},
      .arr{3, 3, 3},
      .map{{"verbose", 1}},
    },
  };
  std::string buffer =
    R"({"j":287,"bye":"Hello World","triplet":[1,2,3],"dict":{"one":1,"two":2},)"
    R"("config":{"i":1,"hello":"No","arr":[3,3,3],"map":{"verbose":1}}})";
  impluct obj = impluct_from_json(buffer);
  CHECK(obj.j == equivalent.j);
  CHECK(obj.bye == equivalent.bye);
  CHECK(obj.triplet == equivalent.triplet);
  CHECK(obj.dict == equivalent.dict);
  CHECK(obj.config.i == equivalent.config.i);
}

TEST_CASE("testing the json dump of the default confluct") {
  confluct obj{};
  std::string expected =
    R"({"i":0,"hello":"","arr":[0,0,0],"map":{}})";
  CHECK(to_json(obj) == expected);
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
  std::string xml = R"({"invalid-values":true})";
  auto config = confluct_from_json(xml);
  CHECK(config.i == empty.i);
  CHECK(config.hello == empty.hello);
  CHECK(config.arr == empty.arr);
  CHECK(config.map == empty.map);
}

TEST_CASE("testing failing confluct load from (invalid) json") {
  confluct empty{};
  std::string xml = R"({"invalid-values":[})";
  auto config = confluct_from_json(xml);
  CHECK(config.i == empty.i);
  CHECK(config.hello == empty.hello);
  CHECK(config.arr == empty.arr);
  CHECK(config.map == empty.map);
}

TEST_CASE("testing confluct load from toml") {
  std::string  some_toml = R"(i = 287
  hello = "Hello World"
  arr = [ 1, 2, 3 ]

  [map]
  one = 1
  two = 2
  )";
  auto config = confluct_from_toml(some_toml);
  CHECK(config.i == 287);
  CHECK(config.hello == std::string{"Hello World"});
  CHECK(config.arr == std::array<uint64_t, 3>{1, 2, 3});
  CHECK(config.map == std::map<std::string, int>{{"one", 1}, {"two", 2}});
}

TEST_CASE("testing confluct load from toml with missing values") {
  std::string some_toml = R"(i = 287
  arr = [ 1, 2, 3 ]

  [map]
  one = 1
  two = 2
  )";
  auto config = confluct_from_toml(some_toml);
  CHECK(config.i == 287);
  CHECK(config.hello == std::string{""});
  CHECK(config.arr == std::array<uint64_t, 3>{1, 2, 3});
  CHECK(config.map == std::map<std::string, int>{{"one", 1}, {"two", 2}});
}

TEST_CASE("testing confluct load from invalid toml") {
  std::string some_toml = R"(i = 287
  arr = [ 1, 2, 3 ] [
  )";
  auto config = confluct_from_toml(some_toml);
  CHECK(config.i == 0);
  CHECK(config.hello == std::string{""});
  CHECK(config.arr == std::array<uint64_t, 3>{0, 0, 0});
  CHECK(config.map == std::map<std::string, int>{});
}

TEST_CASE("testing confluct load from xml") {
  std::string xml =
    R"(<config><i>287</i><hello>Hello World</hello><arr>1</arr><arr>2</arr><arr>3</arr>)"
    R"(<map><one>1</one><two>2</two></map></config>)";
  auto config = confluct_from_xml(xml);
  CHECK(config.i == 287);
  CHECK(config.hello == std::string{"Hello World"});
  CHECK(config.arr == std::array<uint64_t, 3>{1, 2, 3});
  CHECK(config.map == std::map<std::string, int>{{"one", 1}, {"two", 2}});
}

TEST_CASE("testing conflicted confluct load from xml") {
  std::string xml =
    R"(<config><j>287</j><hello>Hello World</hello><arr>1</arr><arr>2</arr><arr>3</arr>)"
    R"(<map><one>1</one><two>2</two></map></config>)";
  auto config = confluct_from_xml(xml);
  CHECK(config.i == 0);  // Default value because we replaced the i node in xml input with a j node
  CHECK(config.hello == std::string{"Hello World"});
  CHECK(config.arr == std::array<uint64_t, 3>{1, 2, 3});
  CHECK(config.map == std::map<std::string, int>{{"one", 1}, {"two", 2}});
}

TEST_CASE("testing failing confluct load from xml") {
  confluct empty{};
  std::string buffer = R"(<config></config>)";
  auto config = confluct_from_xml(buffer);
  CHECK(config.i == empty.i);
  CHECK(config.hello == empty.hello);
  CHECK(config.arr == empty.arr);
  CHECK(config.map == empty.map);
}

TEST_CASE("testing failing confluct load from xml (not well-formed)") {
  confluct empty{};
  std::string buffer = R"(<config><i>42</config>)";
  auto config = confluct_from_xml(buffer);
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

TEST_CASE("testing that different calls to uuid4() yield distinct strings") {
  int const some = 42;
  std::vector<std::string> uuids{};
  for (int i=0; i < some; ++i) uuids.push_back(uuid4());

  for (int i=0; i < some; ++i) {
    auto id_i = uuids[i];
    for (int j=0; j < some; ++j) {
      if (i != j) {
        auto id_j = uuids[j];
        CHECK(id_i != id_j);
      }
    }
  }
}
