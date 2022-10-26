#include "../include/ex2.h"

void int_printer(string label, vector<int>& v) {
    cout << label << ": ";

    for (int i : v) 
        cout << i << " ";
    cout << "\n";
}
