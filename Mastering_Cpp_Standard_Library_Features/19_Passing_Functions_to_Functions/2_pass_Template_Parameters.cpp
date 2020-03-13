// g++ 2_pass_Template_Parameters.cpp -Wall -Wextra -std=gnu++2a

/*
Pros:
1. Zero-overhead: compiler can aggressively inline and optimize
2. Flexibility: Any FunctionObjects can be passed

Cons:
1. Possible compilation time degradation
2. Possible code bloat
3. Hard to constrain to a particular signature
    (refer to call_with_zero_v2 to see why it is hard)
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
//---------------------------------------------
template <typename F>
auto call_with_zero_v2(F&& f)
    -> std::enable_if_t<
        std::is_invocable_r_v<F&&, int>
    >
{
    f(0);
}
//---------------------------------------------
template <typename F>
auto call_with_zero_v3(F&& f) -> decltype(f(0), void())
{
    f(0);
}
//---------------------------------------------
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
    std::cout << "test with template:\n";
    call_with_zero(foo);
    call_with_zero(S{});
    call_with_zero([i = 0](int) mutable { std::cout << "I am a lambda\n"; });

    // call_with_zero_v2(foo);

    std::cout << "test with template plus SFINAE:\n";
    call_with_zero_v3(foo);

    // When passing Callable objs, use std::invoke
    std::cout << "test with template plus invoke:\n";
    call_member_function(&bar::memfunc);

    return 0;
}