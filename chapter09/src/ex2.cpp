#include "../include/std_lib_facilities.h"

class Name_pairs {
    public:
        void read_names();
        void read_ages();
        void sort_pairs();
        void print();
    private:
        vector<string> names;
        vector<double> ages;
};

void Name_pairs::read_names() {
    cout << "Enter some names. Type 'DONE' when you're finished.\n";

    for (string s; cin >> s; ) {
        if (s == "DONE") return;
        names.push_back(s);
    }
}

void Name_pairs::read_ages() {
    cout << "For each name, enter the person's age.\n";

    for (string s: names) {
        cout << s << " => ";
        int a;
        cin >> a;
        ages.push_back(a);
    }
}

void Name_pairs::sort_pairs() {
    
}

void Name_pairs::print() {
    for (int i = 0; i < names.size(); ++i)
        cout << names[i] << " is " << ages[i] << " years old.\n";
}

int main() {
    try {
        Name_pairs np;
        np.read_names();
        np.read_ages();
        np.sort_pairs();
        np.print();
    }
    catch(exception& e) {
        cerr << e.what();
    }
    catch(...) {
        cerr << "unknown error\n";
    }
    return 0;
}
