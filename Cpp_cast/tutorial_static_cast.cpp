// g++ static_cast_tutorial.cpp -Wall -Wextra -std=gnu++2a

#include <iostream>
#include <string>

void func_1()
{
    std::cout << "in func_1\n";

    float f = 3.5;
    int a;

    a = f;
    a = static_cast<int>(f);
}

class Int {
public:
    int x;
    Int(int _x = 0) : x{_x} {
        std::cout << "conversion constructor\n";
    }
    operator std::string () {
        std::cout << "conversion operator\n";
        return std::to_string(x);
    }
};

void func_2()
{
    std::cout << "in func_2\n";

    Int obj(10);

    std::string str_1 = obj;
    std::cout << "str_1 = " << str_1 << "\n";
    obj = 20;
    std::cout << "obj.x = " << obj.x << "\n";

    std::string str_2 = static_cast<std::string>(obj);
    std::cout << "str_2 = " << str_2 << "\n";
    obj = static_cast<Int>(30);
    std::cout << "obj.x = " << obj.x << "\n";
}

void func_3()
{
    std::cout << "in func_3\n";

    char c;
    int *p = (int*)&c;
    *p = 5;

    // int *ip = static_cast<int*>(&c); // compile fail
}

class Base {};
class Derived : private Base {};

void func_4()
{
    std::cout << "in func_4\n";

    Derived d_1;
    Base *bp_1 = (Base*)&d_1;  // allowed at compile-time
    // Base *bp_2 = static_cast<Base*>(&d_1); // not allowed at compile-time
}

// void func_5() // Use for all upcasts, but never use for confused downcast

void func_6()
{
    std::cout << "in func_6\n";

    int i = 10;
    void *v = static_cast<void*>(&i);
    int *ip = static_cast<int*>(v);
}

int main()
{
    func_1();
    func_2();
    func_3();
    func_4();

    func_6();

    return 0;
}