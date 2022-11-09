#include <iostream>
#include "llist.h"

void f()
{
    List<int> lst; for (int x; std::cin >> x;) lst.push_front(x);

    List<int>::iterator p = high(lst.begin(), lst.end());
    std::cout << "the highest value was " << *p << "\n";
}

int main()
try {
    List<int> l;
    l.push_front(1);
    l.push_front(3);
    l.push_front(2);

    std::cout << "size: " << l.size() << "\n";
    l.print();
    std::cout << "\n";

    List<int>::iterator p2 = high(l.begin(), l.end());
    if ( p2 != l.end() )
        std::cout << "High = " << *p2 << "\n";

    List<int> li1;
    std::cout << "Empty list size: " << li1.size() << "\n";

    List<int> li2 {9};
    std::cout << "int initiated size: " << li2.size() << "\n";
    li2.print();

    for (auto& l : li2)
        l = 7;
    li2.print();

    List<char> lc1;
    lc1.push_front('a');
    lc1.push_back('t');

    auto pi = lc1.begin();
    ++pi;
    lc1.insert(pi, 'y');
    lc1.insert(pi, 'k');
    lc1.insert(pi, 'u');
    lc1.print();

    f();

    return 0;
}
catch(std::exception& e)
{
    std::cout << e.what() << "\n";
    return 1;
}
catch(...)
{
    std::cout << "unknown exception\n";
    return 2;
}
