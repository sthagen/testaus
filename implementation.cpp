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
