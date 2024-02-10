#include <iostream>
#include "../src/implementation.h"
int main() {
  std::cout << "Please enter three integers separated by spaces: ";
  int a{}, b{}, c{};
  std::cin >> a >> b >> c;
  std::cout << "Thanks. Got it.\n";
  std::cout << " triple_max(" << a << ", " << b << ", " << c << ") = " << triple_max(a, b, c) << '\n';
}