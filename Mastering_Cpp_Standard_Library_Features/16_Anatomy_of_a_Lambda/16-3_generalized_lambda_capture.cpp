// g++ 16-3_generalized_lambda_capture.cpp -Wall -Wextra -std=gnu++2a

#include <utility>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>

void sink(std::unique_ptr<int> up)
{
    std::cout << "inside sink\n";
}

int main()
{
    std::cout << "declare l_1\n";
    auto l_1 = [i = 0]{};
    /*
    struct anonymous
    {
        int i = 0;
        auto operator()() const {}
    };
    */

    std::cout << "declare l_2\n";
    int j = 1;
    auto l_2 = [i = j]{};
    /*
    struct anonymous
    {
        int i = 0;
        anonymous(int j) : i{j} {}
        auto operator()() const {}
    };
    */

    std::cout << "declare l_3\n";
    auto l_3 = [i = 0]() mutable { return i++; };
    assert(l_3() == 0);
    assert(l_3() == 1);
    assert(l_3() == 2);
    assert(l_3() == 3);
    assert(l_3() == 4);

    std::cout << "declare l_4\n";
    auto up_1 = std::make_unique<int>();
    auto l_4 = [up = std::move(up_1)] {};

    std::cout << "declare l_5\n";
    auto up_2 = std::make_unique<int>();
    // be careful, need "mutable" key word
    auto l_5 = [up = std::move(up_2)]() mutable
                {
                    sink(std::move(up));
                };
    l_5();

    return 0;
}