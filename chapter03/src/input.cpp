// read and write a first name
#include "../include/std_lib_facilities.h"

int main()
{
    cout << "Please enter your first name and age:\n";
    string first_name = "???";      // first_name is a variable of type string
    double age = 0;
    cin >> first_name;      // read characters into first_name
    cin >> age;
    cout << "Hello, " << first_name << "(age " << age * 12 << ")\n";
}
