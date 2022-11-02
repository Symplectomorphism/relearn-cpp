#include "../lib/std_lib_facilities.h"

const int mymax = 100;
int gai[mymax];                   // a global array (of 100 ints); "lives forever"

void f(int n)
{
    char lac[20];               // local array; "lives" until the end of scope
    int lai[60];
    double lad[n];              // error: array size not a constant
    for (int i=0; i<n; ++i)
        cout << lad[i] << "\n";
}

void f2()
{
    char lac[20];               // local array; "lives" until the end of scope

    lac[7] = 'a';
    *lac = 'b';                 // equivalent to lac[0] = 'b'

    // lac[-2] = 'b';              // huh?
    // lac[200] = 'c';             // huh?
}

int main() {
    int n = 0;
    cin >> n;
    f(n);

    f2();

    return 0;
}
