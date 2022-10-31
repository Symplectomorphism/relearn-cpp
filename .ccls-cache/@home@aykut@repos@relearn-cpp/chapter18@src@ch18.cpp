#include "MyVector.h"
// #include "../lib/std_lib_facilities.h"

void f(int n)
{
    MyVector v(3);      // define a vector of 3 elements
    v.set(2, 2.2);      // set v[1] to 2.2
    MyVector v2 {v};    // same as the line below.
    // MyVector v2 = v;

    v.set(1, 99);
    v2.set(0, 88);
    cout << v.get(0) << " " << v2.get(1) << "\n";
}

void f2(int n)
{
    MyVector v(3);          // define a vector
    v.set(2, 2.2);
    MyVector v2(4);
    v2 = v;

    v.set(1, 99);
    v2.set(0, 88);
    // cout << &v2 << "\n";
    cout << v.get(0) << " " << v2.get(1) << "\n";
}

MyVector fill(istream& is)
{
    int i = 0;
    MyVector res(2);
    for (double x; is >> x;) {
        res.set(i, x);
    }
    return res;
}

void use()
{
    MyVector vec = fill(cin);
    // ... use vec ...
    cout << "vec = " << vec.get(0) << ", " << vec.get(1) << "\n";
}

int main()
{
    MyVector v1 {1, 2, 3};
    MyVector v2(3);

    f(12); 
    f2(23);
    use();

    return 0;
}
