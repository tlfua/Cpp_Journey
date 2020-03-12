// g++ less_than.cpp -Wall -Wextra -std=gnu++2a

#include <iostream>

int main()
{
    const auto less_than = [](int x)
    {
        return [x](int y)
        {
            return y < x;
        };
    };

    auto less_than_five = less_than(5);
    assert(less_than_five(3));
    assert(!less_than_five(10));
    assert(less_than(5)(-20));

    return 0;
}