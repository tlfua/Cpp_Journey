// g++ 15-2_lambda_do_not_produce_overhead.cpp -Wall -Wextra -std=gnu++2a

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>

int foo()
{
    const auto l = []{ return 10; };
    return l();
}

int bar()
{
    const auto l = [](int a, int b)
    {
        return a + b;
    };
    return l(1, l(2, l(3, 4)));
}

int main()
{
    std::cout << foo() << "\n";
    std::cout << bar() << "\n";
    return 0;
}