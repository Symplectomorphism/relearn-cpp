#include <iostream>
#include "llist.h"

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
