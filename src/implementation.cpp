#include <glaze/glaze.hpp>
#include <spdlog/spdlog.h>
#include <yaml-cpp/yaml.h>

#include "implementation.h"

// Naive maximum of three integer values to test compact single-line branch coverage reporting
auto triple_max(int a, int b, int c) -> int { return (a > b) && (a > c) ? a : ( b > c ? b : c ); }

// Spread some logic for aggregation of branches verification in coverage reports
auto spread_logic(int a) -> int {
  int const b{42};
  if ( a > 0 ) {
    int const c{2 * a};
    if (c > b) {
      return c;
    } else {
      return b;
    }
    int const dead_code{};
    return dead_code;
  }
  return b;
}

// Do some weird switch stuff
auto switch_logic(int a) -> int {
  int const b{42};
  switch (a) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9: {
      return 9;  // because typical switches are riddles
    }
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23: {
      int const c{2 * a};
      if (c > b) {
        return c;
      } else {
        return b;
      }
      int const dead_code{};
      return dead_code;
      break;
    }
    default:
      return b;
  }
}

// Bake me a json string
auto to_json(impluct obj) -> std::string { return glz::write_json(obj); }

// Eat my cake
auto impluct_from_json(std::string buffer) -> impluct {
  impluct obj{};
  auto ec = glz::read_json(obj, buffer); // populates object from buffer
  if (ec) {
    spdlog::error("Parsing of ({}) failed with code ({})", buffer, ec);
  } else {
    spdlog::info("Parsing succeeded - to demonstrate arc/branches for log of constant content");
  }
  return obj;
}

// Bake me a yaml string
auto to_yaml(confluct obj) -> std::string {
  YAML::Node node;
  node["i"] = obj.i;
  node["hello"] = obj.hello;
  node["arr"] = obj.arr;
  node["map"] = obj.map;

  std::ostringstream os;
  os << node;
  return os.str();
}

// Eat my json confake
auto confluct_from_json(std::string buffer) -> confluct {
  confluct obj{};
  auto ec = glz::read_json(obj, buffer); // populates object from buffer
  if (ec) {
    spdlog::error("Parsing of ({}) failed with code ({})", buffer, ec);
  }
  return obj;
}

// Eat my yummie confake
auto confluct_from_yaml(std::string buffer) -> confluct {
  auto data = YAML::Load(buffer);
  return {
    .i = data["i"].as<int>(),
    .hello = data["hello"].as<std::string>(),
    .arr = data["arr"].as<std::array<uint64_t, 3> >(),
    .map = data["map"].as<std::map<std::string, int> >(),
  };
}
