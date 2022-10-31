#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

ostream& print_array(ostream& os, int* a, int n)
{
    for (int i=0; i<n; ++i)
        os << a[i] << "\n";
    return os;
}

ostream& print_vector(ostream& os, vector<int>& v)
{
    for (int vv : v)
        os << vv << "\n";
    return os;
}


int main()
try {
    // Drill 01 - free-store allocation.
    int* arr10 = new int[10];

    print_array(cout, arr10, 10);
    delete[] arr10;

    arr10 = new int[10];
    for(int i=0; i<10; ++i)
        arr10[i] = 100+i;
    print_array(cout, arr10, 10);
    delete[] arr10;

    int* arr11 = new int[11];
    for(int i=0; i<11; ++i)
        arr11[i] = 100+i;
    print_array(cout, arr11, 11);
    delete[] arr11;

    vector<int> v10(10);
    int y = 100;
    for (int& v : v10) {
        v = y;
        y++;
    }
    print_vector(cout, v10);

    // Drill 02 - pointers and arrays
    int x = 7;
    int* p1 = &x;

    cout << "p1 = " << p1 << ", " << "*p1 = " << *p1 << "\n";

    int* p2 = new int[7];

    p2[0] = 1;
    for (int i = 1; i < 7; ++i) {
        p2[i] = 2 * p2[i-1];
    }

    cout << "address of p2: " << p2 << "\n";
}
catch(exception& e) {
    cerr << "Exception: " << e.what() << "\n";
    return 1;
}
catch(...) {
    cerr << "Unknown exception\n";
    return 2;
}
