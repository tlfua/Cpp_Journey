// g++ ++num_vs_num++.cpp -Wall -Wextra -std=gnu++2a

#include <iostream>

class Num
{
    int i;
public:
    Num(int _i) : i(_i){}

    Num operator++()
    {
        std::cout << "call prefix\n";
        i = i + 1;
        return *this;
    }
    Num operator++(int)
    {
        std::cout << "call postfix\n";
        Num copy(*this);
        i = i + 1;
        return copy;
    }
    void display() { std::cout << i << "\n"; }
};

int main()
{
    Num num(1);
    ++num;
    num.display();
    num++;
    num.display();
    
    return 0;
}