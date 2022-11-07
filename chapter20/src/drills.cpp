#include <iostream>
#include <vector>
#include <list>
#include <array>
#include <algorithm>

using namespace std;

int factor {2};

int increase(int n) {
    return n + factor;
}

void print(int n) {
    cout << n << "\n";
}

// Drill 6.
template<typename Iterator1, typename Iterator2>
Iterator2 mycopy(Iterator1 f1, Iterator1 e1, Iterator2 f2)
{
    if (f1 == e1)
        return f2;

    while ( f1 != e1 ) {
        *f2 = *f1;

        ++f2;
        ++f1;
    }
    return f2;
}

int main()
try {
    // Drill 1.
    array<int, 10> a {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, };

    // Drill 2.
    vector<int> v(a.begin(), a.end());      // pg. 1148 of Programming.

    // Drill 3.
    list<int> l(a.begin(), a.end());

    // Drill 4.
    array<int, 10> a2 = a;
    vector<int> v2 = v;
    list<int> l2 = l;

    // Drill 5.
    transform(a2.begin(), a2.end(), a2.begin(), increase);
    for_each(a2.begin(), a2.end(), print);
    
    cout << "\n";

    factor = 3;
    transform(v2.begin(), v2.end(), v2.begin(), increase);
    for_each(v2.begin(), v2.end(), print);

    cout << "\n";

    factor = 5;
    transform(l2.begin(), l2.end(), l2.begin(), increase);
    for_each(l2.begin(), l2.end(), print);

    cout << "\n";

    // Drill 7.
    mycopy(a.begin(), a.end(), v2.begin());
    for_each(v2.begin(), v2.end(), print);

    cout << "\n";

    mycopy(l2.begin(), l2.end(), a.begin());
    for_each(a.begin(), a.end(), print);
    
    cout << "\n";

    // Drill 8.
    int target_val = 3;
    vector<int>::iterator v_iter = find(v2.begin(), v2.end(), target_val);

    if ( v_iter != v2.end() ) {
        vector<int>::difference_type diff = v_iter - v2.begin();
        cout << "position of value: " << *v_iter << " is: " << diff << "\n";
    }

    target_val = 27;
    list<int>::iterator l_iter = find(l2.begin(), l2.end(), target_val);

    if (l_iter != l2.end() ) {
        list<int>::iterator temp {l2.begin()};
        int position = 0;

        while (temp != l_iter) {
            ++position;
            ++temp;
        }

        cout << "position of value: " << *l_iter << " is: " << position << "\n";
    }
    else {
        cout << "Element not found!\n";
    }
}
catch(std::exception& e) {
    std::cout << e.what() << "\n";
    return 1;
}
catch(...) {
    std::cout << "unknown exception\n";
    return 2;
}
