#include "../include/std_lib_facilities.h"
#include "../include/ex2.h"


void fibonacci(vector<int>& v, int n) {
    if (n < 2) error("You must request at least 2 Fibonacci numbers.\n");

    int pre = 1;
    int cur = 2;
    int temp = 0;
    v.push_back(pre);
    v.push_back(cur);

    for (int i = 2; i < n; i++) {
        temp = cur;
        cur += pre; 
        v.push_back(cur);
        pre = temp;
    }
}


int main() {
    vector<int> ints;

    cout << "How many Fibonacci numbers would you like to see?\n";
    int number_of_fibs;
    cin >> number_of_fibs;

    fibonacci(ints, number_of_fibs);

    int_printer("Fibonacci", ints);

    return 0;
}
