#include "../lib/std_lib_facilities.h"

// a very simplified vector of doubles (like vector<double>)
class MyVector {
    int sz;                             // the size
    double* elem;                       // the pointer to the first element (of
                                        // type double)
    public: 
        MyVector(int s);                // constructor 1        
        MyVector(initializer_list<double> lst); // constructor 2
        ~MyVector() { delete[] elem; }  // destructor: free memory

        MyVector(const MyVector&);        // copy constructor
        MyVector& operator=(const MyVector&);       // copy assignment

        MyVector(MyVector&& vec);           // move constructor
        MyVector& operator=(MyVector&&);    // move assignment
        
        int size() const { return sz; } // the current size

        double get(int n) const { return elem[n]; }
        void set(int n, double v) { elem[n] = v; }
};
