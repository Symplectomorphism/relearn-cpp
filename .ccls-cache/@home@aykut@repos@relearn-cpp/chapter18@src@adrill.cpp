#include "../lib/std_lib_facilities.h"

int ga[10] {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};


void f(int v[], int n)
{
    int la[10] {  };
    for (int i=0; i<n; ++i) la[i] = ga[i];

    cout << "Local copy\n";
    for (const auto& a : la)
        cout << a << " ";
    cout << "\n";

    int* p = new int[n];
    for (int i=0; i<n; ++i) p[i] = v[i];

    cout << "Pointer to free store\n";
    for (int i=0; i<n; i++)
        cout << p[i] << " ";
    cout << "\n";
    
    delete[] p;
}

int fac(int n) { return n > 1 ? n*fac(n-1) : 1; }

int main()
{
    f(ga, 10);

    int aa[10] {};
    for (int i=0; i<10; ++i)
        aa[i] = fac(i+1);
    cout << "Factorial array\n";
    f(aa, 10);

    return 0;
}
