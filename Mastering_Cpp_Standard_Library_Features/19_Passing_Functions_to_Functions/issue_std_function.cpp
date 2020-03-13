// g++ issue_std_function.cpp -Wall -Wextra -std=gnu++2a

#include <cmath>
#include <functional>
#include <iostream>

void foo(std::function<void()> f)
{
    f();
}

void some_function(){}

int main()
{
    foo(std::function<void()>{}); // empty
    foo([]{});                    // owning
    foo(std::ref(some_function)); // non-owning

    return 0;
}