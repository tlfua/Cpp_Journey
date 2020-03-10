// g++ 17-2_avoid_using_mem_fn_and_bind.cpp -Wall -Wextra -std=gnu++2a

#include <utility>
#include <iostream>
#include <cstdlib>
#include <functional>
#include <algorithm>
#include <vector>

struct foo
{
    int x = 0;
    void print() { std::cout << x << "\n"; }
};

int add(int a, int b)
{
    return a + b;
}

int main()
{
    auto foo_print_v1 = std::mem_fn(&foo::print);
    foo_print_v1(foo{});
    foo_print_v1(foo{5});

    auto foo_print_v2 = [](auto&& this_foo) { this_foo.print(); };
    foo_print_v2(foo{});
    foo_print_v2(foo{5});

    auto add10_v1 = std::bind(add, 10, std::placeholders::_1);
    std::cout << add10_v1(20) << "\n";

    auto add10_v2 = [](auto x) { return add(static_cast<decltype(x)>(10), x); };
    std::cout << add10_v2(20) << "\n";

    return 0;
}