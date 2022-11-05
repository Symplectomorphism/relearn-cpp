// #include "../lib/std_lib_facilities.h"
#include <iostream>
#include <string>
#include <vector>

template<typename T>
struct S
{
    public:
        // constructor
        S(): val(T()) { }
        explicit S(T v): val{v} { }

        T& get();
        const T& get() const;

        void set(const T& v);
        S& operator=(const T&); // copy assignment
    private: 
        T val;
};

template<typename T>
T& S<T>::get()
{
    return val;
}

template<typename T>
const T& S<T>::get() const
{
    return val;
}

template<typename T>
void S<T>::set(const T& v) { val = v; }

template<typename T>
S<T>& S<T>::operator=(const T& t)
{
    val = t;
    return *this;
}

template<typename T>
void read_val(T& v)
{
    std::cin >> v;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T>& v)
{
    os << "{ ";
    for (int i=0; i<v.size(); ++i){
        os << v[i] << (i < v.size() -1 ? ", ": " ");
    }
    os << "}\n";

    return os;
}

template<typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& v)
{
    char ch = 0;
    is >> ch;
    if (ch != '{') {
        is.unget();
        return is;
    }

    for (T val; is >> val; ) {
        v.push_back(val);
        is >> ch;
        if (ch != ',') break;
    }

    return is;
}

int main()
try {
    // Drill 3
    S<int> s_int(5);
    S<char> s_char('x');
    S<double> s_double(3.14159265358979);
    S<std::string> s_string("My String");
    std::vector<int> vi;
    vi.push_back(1);
    vi.push_back(2);
    vi.push_back(3);
    S< std::vector<int> > s_v_int {vi};

    // Drill 4
    std::cout << "s_int: " << s_int.get() << "\n"
              << "s_char: " << s_char.get() << "\n"
              << "s_double: " << s_double.get() << "\n"
              << "s_string: " << s_string.get() << "\n";
    for (int i=0; i<s_v_int.get().size(); ++i)
        std::cout << "s_v_int[" << i << "]: " << s_v_int.get()[i] << "\n";

    // Drill 11
    const S<int> c_s_int {5};
    std::cout << "\nc_s_int: " << c_s_int.get() << "\n";    // requires const
                                                            // getter

    // Drill 13
    std::cout << "\ns_int: ";
    int ii;
    read_val(ii);
    s_int = ii;
    std::cout << "s_int: " << s_int.get() << "\n";

    std::cout << "\ns_char: ";
    char c;
    read_val(c);
    s_char = c;
    std::cout << "s_char: " << s_char.get() << "\n";

    // Drill 14
    std::cout << "vector<int>: (format: { val1, val2, val3, ... }) ";
    std::vector<int> vi2;
    read_val(vi2);
    S<std::vector<int>> svi2 {vi2};

    std::cout << "S<vector<int>> read: " << svi2.get() << "\n";

    std::cout << "vector<char>: (format: { char1, char2, char3, ... }) ";
    std::vector<char> vc2;
    read_val(vc2);
    S<std::vector<char>> svc2 {vc2};

    std::cout << "S<vector<char>> read: " << svc2.get() << "\n";
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << "\n";
    return 1;
}
catch(...){
    std::cerr << "Unknown exception\n";
    return 2;
}

