#include <iostream>

#include "../src/implementation.h"

int main() {
  std::cout << "Please enter three integers separated by spaces: ";
  int a{}, b{}, c{};
  std::cin >> a >> b >> c;
  std::cout << "Thanks. Got it.\n";
  std::cout << " triple_max(" << a << ", " << b << ", " << c << ") = " << triple_max(a, b, c) << '\n';

  std::string buffer = R"({"i":287,"hello":"Hello World","arr":[1,2,3],"map":{"one":1,"two":2}})";
  auto config = confluct_from_json(buffer);
  std::cout << "\n ... and now for something completely differnt:\n";
  std::cout << to_yaml(config) << '\n';
}
