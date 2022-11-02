#include "MyVector.h"
// #include "../lib/std_lib_facilities.h"


struct X {              // simple test class
    int val;

    void out(const string& s, int nv)
    { cerr << this << "->" << s << ": " << val << " (" << nv << ")\n"; }

    X() { out("X()", 0); val=0; }       // default constructor
    X(int v) { val = v; out( "X(int)", v ); }
    X(const X& x) { val=x.val; out("X(X&) ", x.val); }      // copy constructor
    X& operator=(const X& a)                                    // copy assignment
    { out("X::operator=()", a.val); val = a.val; return *this; }
    ~X() { out("~X()", 0); }
};

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

X glob(2);              // a global variable

X copy(X a) { return a; }

X copy2(X a) { X aa = a; return aa; }

X& ref_to(X& a) { return a; }

X* make(int i) { X a(i); return new X(a); }

struct XX { X a; X b; };

void ff(const MyVector& cv, MyVector& v)
{
    // double d = cv[1];       // fine (uses the const [])
    // cv[1] = 2.0;            // error( uses the const [] )
    double d = v[1];        // fine (uses the non-const [])
    v[1] = 2.0;             // fine (uses the non-const [])
}

int main()
{
    MyVector v1 {1, 2, 3};
    MyVector v2(3);

    f(12); 
    f2(23);
    // use();

    /*
    X loc {4};          // local variable
    X loc2 {loc};       // copy construction
    loc = X{5};         // copy assignment
    loc2 = copy(loc);   // call by value and return;
    loc2 = copy2(loc);
    X loc3 {6};
    X& r = ref_to(loc); // call by reference and return
    delete make(7);
    delete make(8);
    vector<X> v(4);     // default values
    XX loc4;
    X* p = new X{9};    // an X on the free store
    delete p;
    X* pp = new X[5];   // an array of Xs on the free store
    delete[] pp;
    */

    MyVector v(10);
    for (int i=0; i<v.size(); ++i) {
        v[i] = i;
        cout << v[i];
    }
    cout << "\n";

    return 0;
}
