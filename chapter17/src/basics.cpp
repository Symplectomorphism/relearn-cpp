#include "std_lib_facilities.h"
#include "MyVector.h"

void sizes(char ch, int i, int* p, bool b, double d, vector<int> v) {
    cout << "the size of char is " << sizeof(char) << ' ' << sizeof(ch) << "\n";
    cout << "the size of int is " << sizeof(int) << ' ' << sizeof(i) << "\n";
    cout << "the size of int* is " << sizeof(int*) << ' ' << sizeof(p) << "\n";
    cout << "the size of bool is " << sizeof(bool) << ' ' << sizeof(b) << "\n";
    cout << "the size of double is " << sizeof(double) << ' ' << sizeof(d) << "\n";
    cout << "the size of double* is " << sizeof(double*) << ' ' << sizeof(&d) << "\n";
    cout << "the size of vector<int>(1000) is " << sizeof(vector<int>) << ' ' << sizeof(v) << "\n";
}

MyVector* f(int s)
{
    MyVector* p = new MyVector(s);        // allocate a vector on the heap
    for (int i=0; i<p->size(); ++i)
        p->set(i, i+1);
    cout << "p = " << p << ", size() = " << p->size() << "\n";
    for (int i=0; i<p->size(); ++i)
        cout << "p[" << i << "]==" << p->get(i) << "\n";
    return p;
}

void ff()
{
    MyVector* q = f(4);
    cout << "q = " << q << ", size() = " << q->size() << "\n";
    for (int i=0; i<q->size(); ++i)
        cout << "q[" << i << "]==" << q->get(i) << "\n";

    delete q;
}

int incr_v(int x) { return x+1; }
void incr_p(int* p) 
{ 
    if (p==nullptr) error("null pointer argument to incr_p()");
    ++*p; 
}

void incr_r(int& r) { ++r; }

int main() {
    vector<double> age(4);      // a vector with 4 elements of type double
    age[0] = 0.33;
    age[1] = 22.0;
    age[2] = 27.2;
    age[3] = 54.2;

    char c = 'A';
    int var = 17;
    int* pi = &var;
    bool b = false;
    double d = 1.23;
    vector<int> v(1000);

    sizes(c, var, pi, b, d, v);

    MyVector myvec(5);
    for (int i=0; i<myvec.size(); ++i) {
        myvec.set(i, 1.1*i);
        cout << "myvec[" << i << "]==" << myvec.get(i) << "\n";
    }

    ff();

    int x = 7;
    incr_p(&x);
    incr_r(x);

    cout << "r = " << x << "\n";

    incr_p(nullptr);        // SEGFAULT!
}
