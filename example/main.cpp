#include <iostream>

#include <pugixml.hpp>

#include "../src/implementation.h"

int main() {
  std::cout << "Please enter three integers separated by spaces: ";
  int a{}, b{}, c{};
  std::cin >> a >> b >> c;
  std::cout << "Thanks. Got it.\n";
  std::cout << " triple_max(" << a << ", " << b << ", " << c << ") = " << triple_max(a, b, c) << '\n';

  std::string buffer = R"({"i":287,"hello":"Hello World","arr":[1,2,3],"map":{"one":1,"two":2}})";
  auto config = confluct_from_json(buffer);
  std::cout << "\nYAML from JSON:\n---\n";
  std::cout << to_yaml(config) << '\n';

  std::string xml =
    R"(<config><i>287</i><hello>Hello World</hello><arr>1</arr><arr>2</arr><arr>3</arr>)"
    R"(<map><one>1</one><two>2</two></map></config>)";
  pugi::xml_document doc;
  pugi::xml_parse_result result = doc.load_string(xml.c_str());
  if (result) {
    std::cout << "\nYAML from XPath:\n---\n";
    pugi::xpath_node the_i = doc.select_node("/config/i");
    pugi::xpath_node the_hello = doc.select_node("/config/hello");
    pugi::xpath_node_set the_arrs = doc.select_nodes("/config/arr");
    pugi::xpath_node_set the_map = doc.select_nodes("/config/map/descendant-or-self::node()");

    std::cout << "i: " << the_i.node().child_value() << '\n';
    std::cout << "hello: " << the_hello.node().child_value() << '\n';
    std::cout << "arr:\n";
    for (auto the_arr: the_arrs) {
      std::cout << "  - " << the_arr.node().child_value() << '\n';
    }
    std::cout << "map:\n";
    for (auto the_member: the_map) {
      auto value = the_member.node().child_value();
      if (std::string{value} != "") std::cout << "  " << the_member.node().name() << ": " << value << '\n';
    }
    std::cout << '\n';


  } else {
    std::cout << "Error description: " << result.description() << "\n";
    std::cout << "Error offset: " << result.offset << " (error at [..." << (xml.c_str() + result.offset) << "]\n\n";
  }
}
