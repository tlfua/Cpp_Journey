// g++ 2_pass_Template_Parameters.cpp -Wall -Wextra -std=gnu++2a

/*
Pros:
1. Zero-overhead: compiler can aggressively inline and optimize
2. Flexibility: Any FunctionObjects can be passed

Cons:
1. Possible compilation time degradation
2. Possible code bloat
3. Hard to constrain to a particular signature
*/

#include <iostream>
#include <functional>

template <typename F>
void call_with_zero(F&& f) { f(0); }

void foo(int x) { std::cout << "I am a function\n"; }

struct S
{
    void operator()(int x)
    {
        std::cout << "I am a function obj\n";
    }
};
//----
struct bar
{
    void memfunc() { std::cout << "I am a member function of bar\n"; }
};

template <typename F>
void call_member_function(F&& f)
{
    std::invoke(f, bar{});
}

int main()
{
    call_with_zero(foo);
    call_with_zero(S{});
    call_with_zero([i = 0](int) mutable { std::cout << "I am a lambda\n"; });

    // When passing Callable objs, use std::invoke
    call_member_function(&bar::memfunc);

    return 0;
}