// g++ 1_pass_Funtions_pointers.cpp -Wall -Wextra -std=gnu++2a

/*
Pros:
1. Simplicity
2. Compilers can aggressively optimize function pointers

Cons:
1. Very limited use cases
2. Stateful lambdas cannot be passed
3. Generic function objs cannot be passed
*/

#include <iostream>

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }

int execute_operation(int(*op)(int, int), int a, int b)
{
    return op(a, b);
}

int main()
{
    std::cout << execute_operation(add, 3, 2) << "\n";
    std::cout << execute_operation(sub, 3, 2) << "\n";
    std::cout << execute_operation([](int a, int b){ return a * b; }, 3, 2) << "\n";

    return 0;
}