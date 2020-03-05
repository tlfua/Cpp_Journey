// g++ 14-4_capture_by_ref_vs_by_val.cpp -Wall -Wextra -std=gnu++2a

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>

void capture_by_ref()
{
    std::string s = "hello";
    const auto l = [&s]{ std::cout << s << "\n"; };

    l();

    s = "bye";

    l();
}

void capture_by_val()
{
    std::string s = "hello";
    const auto l = [s]{ std::cout << s << "\n"; };

    l();

    s = "bye";

    l();
}

int main()
{
    capture_by_ref();
    capture_by_val();
    return 0;
}