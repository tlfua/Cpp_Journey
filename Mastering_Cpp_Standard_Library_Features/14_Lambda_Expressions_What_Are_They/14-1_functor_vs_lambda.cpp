// g++ 14-1_functor_vs_lambda.cpp -Wall -Wextra -std=gnu++2a

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>

struct person
{
    std::string name;
    int age;
    person(std::string _name, int _age) : name(_name), age(_age) {}
};

struct by_age
{
    bool operator()(const person& a, const person& b) const
    {
        return a.age < b.age;
    }
};

int main()
{
    std::vector<person> people{{"Alice", 20}, {"Bob", 10}};
    
    // sort by functor
    std::sort(std::begin(people), std::end(people), by_age{});
    for (int i = 0; i < people.size(); ++i) {
        std::cout << people[i].name << " " << people[i].age << "  ";
    }
    std::cout << "\n";
    
    // sort by lambda
    std::sort(std::begin(people), std::end(people),
             [](const person& a, const person& b)
              {
                  return a.name < b.name;
              });
    for (int i = 0; i < people.size(); ++i) {
        std::cout << people[i].name << " " << people[i].age << "  ";
    }
    std::cout << "\n";
    
    return 0;    
}
