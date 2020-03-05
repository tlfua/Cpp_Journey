// g++ 15-1.cpp -Wall -Wextra -std=gnu++2a

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>

struct printer
{
    void operator()(int x) const
    {
        std::cout << x << " ";
    }
};

int main()
{
    std::vector<int> v{1, 2, 3, 4, 5};
    
    // C++ 03
    std::for_each(v.begin(), v.end(), printer());
    std::cout << "\n";

    // C++ 11
    std::for_each(v.begin(), v.end(), [](int x)
                                        {
                                            std::cout << x << " ";
                                        });
    std::cout << "\n";

    /*  Above lambda is equivalent to
    struct anonymous_lambda_type
    {
        auto operator()(int x) const { std::cout << x << " "; }
    } 
    */

   auto& os = std::cout;
   std::for_each(v.begin(), v.end(), [&os](int x)
                                        {
                                            os << x << " ";
                                        });
    std::cout << "\n";

    /*  Above lambda is equivalent to
    struct anonymous_lambda_type
    {
        std::ostream& d_os;
        anonymous_lambda_type(std::ostream& os) : d_os(os) {}

        auto operator()(int x) const { d_os << x << " "; }
    }
    */

    return 0;
}