// g++ 17-1.cpp -Wall -Wextra -std=gnu++2a

#include <utility>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>

bool always_true(const int& x)
{
    return true;
}

bool always_true(const float& x)
{
    return true;
}

int main()
{
    std::vector<int> int_vec{1};
    // need explicitly choose overload
    auto it_1 = std::find_if(int_vec.begin(), int_vec.end(), static_cast<bool(*)(const int&)>(always_true));
    std::cout << *it_1 << "\n";

    std::vector<float> float_vec{1.1};
    auto it_2 = std::find_if(float_vec.begin(), float_vec.end(), [](const auto& x){ return true; });
    std::cout << *it_2 << "\n";

    return 0;
}