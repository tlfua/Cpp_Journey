// g++ 16-2_use_cases.cpp -Wall -Wextra -std=gnu++2a

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>


void call_twice()
{
    const auto print = []
    {
        std::cout << "hello\n";
    };
    const auto call_print_twice = [](auto f)
    {
        f();
        f();
    };
    call_print_twice(print);
}

int main()
{
    // 1. forward
    // 2. variadic generic lambda
    // 3.
    call_twice();
    return 0;
}