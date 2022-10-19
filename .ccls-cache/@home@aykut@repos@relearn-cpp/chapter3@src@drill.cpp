// read and write a first name
#include "../include/std_lib_facilities.h"

int main()
{
    cout << "Enter the name of the person you want to write to ";
    string first_name = "???";      // first_name is a variable of type string
    cin >> first_name;      // read characters into first_name
    cout << "Dear " << first_name << ",\n"; // << "(age " << age * 12 << ")\n";
    cout << "    How are you? I am fine. I miss you.\n";
    cout << "Currently, I am working on my C++ review.\n";

    cout << "Enter the name of a friend: ";
    string friend_name = " ";
    cin >> friend_name;
    cout << "Have you seen " << friend_name << " lately?\n";

    char friend_sex = 0;
    cout << "What is the gender of this friend? (m/f): ";
    cin >> friend_sex;
    if (friend_sex == 'm')
        cout << "If you see " << friend_name << " please ask him to call me.\n";
    else
        cout << "If you see " << friend_name << " please ask her to call me.\n";

    cout << "Enter the age of the recipient: ";
    int age;
    cin >> age;
    cout << "I hear you just had a birthday and you are " << age << " years old.\n";

    if (age < 0 || age > 110)
        simple_error("you're kidding!");

    if (age < 12)
        cout << "Next year you will be " << age + 1 << '\n';
    if (age == 17)
        cout << "Next year you will be able to vote.\n";
    if (age > 70)
        cout << "I hope you are enjoying retirement.\n";

    cout << "Yours sincerely,\n\n" << "myCute\n";
}
