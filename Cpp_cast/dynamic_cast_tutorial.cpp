// g++ dynamic_cast_tutorial.cpp -Wall -Wextra -std=gnu++2a

#include <iostream>
#include <exception>

class Base {
    virtual void print() { std::cout << "Base\n"; }
};

class Derived_1: public Base {
    void print() { std::cout << "Derived_1\n"; }
};

class Derived_2: public Base {
    void print() { std::cout << "Derived_2\n"; }
};

int main()
{
    // Derived_1 d_1;

    // Base *bp = dynamic_cast<Base*>(&d_1);
    
    Base *bp;

    bp = dynamic_cast<Base*>(new Derived_1());
    Derived_2 *dp_2 = dynamic_cast<Derived_2*>(bp);
    if (dp_2 == nullptr)
        std::cout << "NULL\n";
    else
        std::cout <<"not NULL\n";

    bp = dynamic_cast<Base*>(new Derived_1());
    Derived_1 *dp_1 = dynamic_cast<Derived_1*>(bp);
    if (dp_1 == nullptr)
        std::cout << "NULL\n";
    else
        std::cout <<"not NULL\n";

    Derived_1 d_1;

    try {
        Derived_2 &rd_2 = dynamic_cast<Derived_2&>(d_1);
        std::cout << "cast successfully\n";
    } catch(std::exception& e) {
        std::cout << e.what() << "\n";
    }

    try {
        Derived_1 &rd_1 = dynamic_cast<Derived_1&>(d_1);
        std::cout << "cast successfully\n";
    } catch(std::exception& e) {
        std::cout << e.what() << "\n";
    }

    return 0;
}