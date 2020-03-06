// g++ 16-1.cpp -Wall -Wextra -std=gnu++2a

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>

void mutable_lambda()
{
    int i = 0;
    auto l = [i]() mutable { return i++; };

    for (int k = 0; k < 5; ++k) {
        std::cout << l() << " ";
    }
    std::cout << "\n";
}

struct anonymous
{
    template <typename T>
    auto operator()(const T& x) const
    {
        std::cout << x << "\n";
    };
};

void generic_lambda()
{
    // C++ 14
    const auto l = [](const auto& x)
    {
        std::cout << x << "\n";
    };

    l("I am inside lambda");

    // The above lambda is equivalent to
    anonymous a;
    a("I am inside functor");
}

int main()
{
    mutable_lambda();
    generic_lambda();
    return 0;
}