#pragma once

#include<map>
#include<string>
#include<tuple>
#include<vector>

// Some simpler struct declaration - maybe as a config type
struct confluct {
  int i;
  std::string hello;
  std::array<uint64_t, 3> arr;
  std::map<std::string, int> map;
};

// Some struct declaration (relying on default zero initializers)
struct impluct {
  int j;
  std::string bye;
  std::array<uint64_t, 3> triplet;
  std::map<std::string, int> dict;
  confluct config;
};

// Some forward declarations
auto triple_max(int, int, int) -> int;
auto spread_logic(int) -> int;
auto switch_logic(int) -> int;
auto to_json(impluct) -> std::string;
auto impluct_from_json(std::string) -> impluct;
auto to_xml(confluct) -> std::string;
auto to_yaml(confluct) -> std::string;
auto confluct_from_json(std::string) -> confluct;
auto confluct_from_xml(std::string) -> confluct;
auto confluct_from_yaml(std::string) -> confluct;
