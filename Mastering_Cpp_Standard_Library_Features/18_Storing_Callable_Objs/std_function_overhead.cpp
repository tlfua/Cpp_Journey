// g++ std_function_overhead.cpp -Wall -Wextra -std=gnu++2a

#include <iostream>
#include <functional>

int with_std_function(std::function<int(int, int)> f)
{
    return f(1, 2);
}

template <typename F>
int with_template(F f)
{
    return f(1, 2);
}

int main()
{
    // w overhead
    std::cout << with_std_function([](int a, int b){ return a + b; }) << "\n";
    std::cout << with_template([](int a, int b){ return a + b; }) << "\n";

    return 0;
}