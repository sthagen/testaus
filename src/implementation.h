#pragma once

#include<map>
#include<string>
#include<tuple>
#include<vector>

// Some struct declaration with default values
struct impluct {
    int i{};
    std::string hello{};
    std::array<uint64_t, 3> arr{};
    std::map<std::string, int> map{};
    std::vector<std::tuple<int, int, int, bool> > speckles{};
};

// Some forward declarations
auto triple_max(int, int, int) -> int;
auto spread_logic(int) -> int;
auto switch_logic(int) -> int;
auto to_json(impluct) -> std::string;
