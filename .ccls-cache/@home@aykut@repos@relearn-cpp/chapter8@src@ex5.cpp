#include "../include/std_lib_facilities.h"
#include "../include/ex2.h"

vector<int> reverse(const vector<int>& v)
{
    vector<int> rev;

    for (int i = v.size()-1; i >= 0; --i)
        rev.push_back(v[i]);
    
    return rev; 
}

void reverse_in_place(vector<int>& v)
{
    int j = v.size() - 1;

    for (int i = 0; i < j - i; ++i) {
        swap(v[i], v[j - i]);
    }
}

int main() {
    vector<int> test_odd = { 1, 3, 5, 7, 9 };
    vector<int> test_even = { 2, 4, 6, 8 };

    cout << "Original Vectors\n"
         << "================\n";

    int_printer("odd", test_odd);
    int_printer("even", test_even);
    cout << "\n";

    cout << "Reversed Vectors\n"
         << "================\n";

    vector<int> reverse_odd = reverse(test_odd);
    vector<int> reverse_even = reverse(test_even);

    int_printer("odd", reverse_odd);
    int_printer("even", reverse_even);
    cout << "\n";

    cout << "Original Vectors\n"
         << "================\n";
    
    int_printer("odd", test_odd);
    int_printer("even", test_even);
    cout << "\n";

    cout << "Originals Reversed\n"
         << "==================\n";

    reverse_in_place(test_odd);
    reverse_in_place(test_even);

    int_printer("odd", test_odd);
    int_printer("even", test_even);
}
