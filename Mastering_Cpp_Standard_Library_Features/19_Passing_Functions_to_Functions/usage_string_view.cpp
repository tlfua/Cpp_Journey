// g++ usage_string_view.cpp -Wall -Wextra -std=gnu++2a

#include <iostream>
#include <string_view>
 
int main()
{
    std::string_view str_view("abcd");
 
    auto begin = str_view.begin();
    auto cbegin = str_view.cbegin();
 
    std::cout << *begin << '\n';
    std::cout << *cbegin << '\n';
 
    std::cout << std::boolalpha << (begin == cbegin) << '\n';
    std::cout << std::boolalpha << (*begin == *cbegin) << '\n';
}