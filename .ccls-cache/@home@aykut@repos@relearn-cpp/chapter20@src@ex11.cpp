#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <algorithm>
#include <time.h>
#include <stdlib.h>

template<typename T>
void print(T begin, T end)
{
    for (auto i = begin; i != end; ++i)
        std::cout << *i << " ";
    std::cout << "\n";
}

void f (std::list<int>& l)
{
    std::vector<double> v{l.begin(), l.end()};

    std::sort(v.begin(), v.end());

    print(v.begin(), v.end());
}

void initialize(std::list<int>& l, size_t n)
{
    srand((unsigned int)time(nullptr));
    for (size_t i = 0; i<n; ++i)
        l.push_back(rand());
}

int main() 
try {
    std::list<int> l;

    size_t elements = 10;
    initialize(l, elements);

    print(l.begin(), l.end());

    f(l);
}
catch(std::exception& e)
{
    std::cout << e.what() << "\n";
    return 1;
}
catch(...)
{
    std::cout << "unknown excpetion\n";
    return 2;
}
