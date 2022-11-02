#include "../lib/std_lib_facilities.h"

vector<int> gv {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

void f(vector<int> v)
{
    vector<int> lv(10);
    lv = gv;

    cout << "Local copy\n";
    for (const auto& a : lv)
        cout << a << " ";
    cout << "\n";

    vector<int> lv2 {v};
    for (const auto& a : lv2)
        cout << a << " ";
    cout << "\n";
}

int fac(int n) { return n > 1 ? n*fac(n-1) : 1; }

int main()
{
    f(gv);

    vector<int> vv(10);
    for (int i=0; i<vv.size(); ++i)
        vv[i] = fac(i+1);
    cout << "Factorial array\n";
    f(vv);

    return 0;
}
