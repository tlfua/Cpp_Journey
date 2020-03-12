#include <iostream>

int main()
{

    auto l_0 = []{};
    static_assert(!std::is_same_v<decltype(l_0), void(*)()>);

    auto l_1 = +[]{};
    static_assert(std::is_same_v<decltype(l_1), void(*)()>);

    return 0;
}