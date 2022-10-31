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
    for (int i = 1; i < 7; ++i)
        p2[i] = 2 * p2[i-1];

    cout << "address of p2: " << p2 << "\n";
    for (int i = 0; i < 7; ++i) {
        cout << p2[i] << "\t";
    }
    cout << "\n";

    int* p3 = p2;
    p2 = p1;
    p2 = p3; 

    cout << "pointer: " << p1 << " points to " << *p1 << "\n";
    cout << "pointer: " << p2 << " points to " << *p2 << "\n";
    cout << "pointer: " << p3 << " points to " << *p3 << "\n";

    delete[] p2;

    p1 = new int[10];
    p2 = new int[10];

    p1[0] = 1;
    for (int i = 1; i < 10; ++i)
        p1[i] = 2 * p1[i-1];
    p2 = p1;

    for (int i=0; i<10; ++i)
        p2[i] = p1[i];

    for(int k=0; k<10; ++k)
        cout << p2[k] << "\t";
    cout << "\n";

    // vectors
    vector<int> v1(10);
    vector<int> v2(10);
    v1[0] = 1;
    for (int i=0; i<10; ++i)
        v1[i+1] = 2 * v1[i];
    v2 = v1;

    for (int v : v2) cout << v << "\t";

    cout << "\n";
}
catch(exception& e) {
    cerr << "Exception: " << e.what() << "\n";
    return 1;
}
catch(...) {
    cerr << "Unknown exception\n";
    return 2;
}
