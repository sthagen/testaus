#include <random>

#include <glaze/glaze.hpp>
#include <pugixml.hpp>
#include <spdlog/spdlog.h>
#include <toml++/toml.h>
#include <uuid.h>
#include <yaml-cpp/yaml.h>

#include "implementation.h"

// Naive maximum of three integer values to test compact single-line branch coverage reporting
auto triple_max(int a, int b, int c) -> int { return (a > b) && (a > c) ? a : ( b > c ? b : c ); }

// Spread some logic for aggregation of branches verification in coverage reports
auto spread_logic(int a) -> int {  // The function ... is never used. (CWE-561)
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
auto switch_logic(int a) -> int {  // The function ... is never used. (CWE-561)
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
      break;  // Consecutive return, break, continue, goto or throw statements are unnecessary. (CWE-561)
    }
    default:
      return b;
  }
}

// Bake me a json string
auto to_json(impluct obj) -> std::string {  // The function ... is never used. (CWE-561)
  return glz::write_json(obj);
}

// Eat my cake
auto impluct_from_json(std::string buffer) -> impluct {  // The function ... is never used. (CWE-561)
  impluct obj{};
  auto ec = glz::read_json(obj, buffer); // populates object from buffer
  if (ec) spdlog::error("Parsing of ({}) failed with code ({})", buffer, ec);
  return obj;
}

// Bake me a json string from confluct
auto to_json(confluct obj) -> std::string {  // The function ... is never used. (CWE-561)
  return glz::write_json(obj);
}

// Bake me a yaml string from confluct
auto to_yaml(confluct obj) -> std::string {  // Function parameter 'obj' should be passed by const reference. (CWE-398)
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
    return {};
  }
  return obj;
}

// Eat my tasty toml cake
auto confluct_from_toml(std::string buffer) -> confluct {  // The function ... is never used. (CWE-561)
  try {
    auto tbl = toml::parse(buffer);
    std::optional<int> i = tbl["i"].value<int>();
    std::optional<std::string> hello = tbl["hello"].value<std::string>();
    auto arr_view = tbl["arr"];
    std::array<uint64_t, 3> arr{
      *(arr_view[0].value<uint64_t>()),
      *(arr_view[1].value<uint64_t>()),
      *(arr_view[2].value<uint64_t>())
    };
    std::optional<int> one_val = tbl["map"]["one"].value<int>();
    std::optional<int> two_val = tbl["map"]["two"].value<int>();
    std::map<std::string, int> map{{"one", *one_val}, {"two", *two_val}};

    return {
      .i = *i,
      .hello = *hello,
      .arr = arr,
      .map = map,
    };
  } catch (...) {
    return {};
  }
}

// Eat my yummie confake
auto confluct_from_yaml(std::string buffer) -> confluct {  // The function ... is never used. (CWE-561)
  auto data = YAML::Load(buffer);
  return {
    .i = data["i"].as<int>(),
    .hello = data["hello"].as<std::string>(),
    .arr = data["arr"].as<std::array<uint64_t, 3> >(),
    .map = data["map"].as<std::map<std::string, int> >(),
  };
}

// Eat my extensible confake
auto confluct_from_xml(std::string buffer) -> confluct {  // The function ... is never used. (CWE-561)
  pugi::xml_document doc;
  pugi::xml_parse_result result = doc.load_string(buffer.c_str());

  if ( ! result ) {
    spdlog::error("Parsing of ({}) failed with code ({})", buffer, result.description());
    return {};
  }

  pugi::xpath_node the_i = doc.select_node("/config/i");
  pugi::xpath_node the_hello = doc.select_node("/config/hello");
  pugi::xpath_node_set the_arrs = doc.select_nodes("/config/arr");
  pugi::xpath_node_set the_map = doc.select_nodes("/config/map/descendant-or-self::node()");
  int i = atoi(the_i.node().child_value());
  std::string hello{the_hello.node().child_value()};

  std::array<uint64_t, 3> arr{};
  int yuck = 0;
  // Don't do this at home!
  for (auto the_arr: the_arrs) arr[yuck++] = atoi(the_arr.node().child_value());  // GCOVR_EXCL_BR_LINE

  std::map<std::string, int> map{};
  // Don't do this at home too!
  for (auto the_member: the_map) {  // GCOVR_EXCL_BR_START
    auto value = the_member.node().child_value();
    if (std::string{value} != "") map[the_member.node().name()] = atoi(value);
  }  // GCOVR_EXCL_BR_STOP

  return {
    .i = i,
    .hello = hello,
    .arr = arr,
    .map = map,
  };
}

// Generate random UUID string
auto uuid4() -> std::string {  // The function ... is never used. (CWE-561)
  std::random_device rd;
  auto seed_data = std::array<int, std::mt19937::state_size> {};
  std::generate(std::begin(seed_data), std::end(seed_data), std::ref(rd));
  std::seed_seq seq(std::begin(seed_data), std::end(seed_data));
  std::mt19937 generator(seq);

  return uuids::to_string(uuids::uuid_random_generator{ generator }());
}
