// g++ 16-4_constexpr_lambdas.cpp -Wall -Wextra -std=gnu++2a

#include <utility>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <array>
#include <vector>

int main()
{
    // C++ 17
    auto l = []{ return 10; };

    /*
    equivalent to
    
    []{ return 10; };
    
    and equivalent to

    struct anonymous
    {
        constexpr auto operator()() { return 10; }
    };
    */

    // valid in C++ 17
    std::array<int, []{ return 10; }()> ints;

    return 0;
}