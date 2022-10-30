#include "std_lib_facilities.h"

void sizes(char ch, int i, int* p, bool b, double d, vector<int> v) {
    cout << "the size of char is " << sizeof(char) << ' ' << sizeof(ch) << "\n";
    cout << "the size of int is " << sizeof(int) << ' ' << sizeof(i) << "\n";
    cout << "the size of int* is " << sizeof(int*) << ' ' << sizeof(p) << "\n";
    cout << "the size of bool is " << sizeof(bool) << ' ' << sizeof(b) << "\n";
    cout << "the size of double is " << sizeof(double) << ' ' << sizeof(d) << "\n";
    cout << "the size of double* is " << sizeof(double*) << ' ' << sizeof(&d) << "\n";
    cout << "the size of vector<int>(1000) is " << sizeof(vector<int>) << ' ' << sizeof(v) << "\n";
}

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
}
