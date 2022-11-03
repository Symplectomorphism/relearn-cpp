#include "../lib/std_lib_facilities.h"

// an almost real vector of Ts
template<typename T, typename A = allocator<T>>
class MyVector {
/*
 * invariant: 
 * if 0 <= n <= sz, elem[n] is element n
 * sz <= space;
 * if sz < space there is space for (space-sz) Ts after elem[sz-1]
 */
    int sz;                             // the size
    T* elem;                       // the pointer to the first element (of
                                        // type T)
    int space;
    A alloc;                     // use allocate to handle memory for elements

    public: 
        MyVector(): sz{0}, elem{nullptr}, space{0} {}
        explicit MyVector(int s);                // constructor 1        
        MyVector(initializer_list<T> lst); // constructor 2
        ~MyVector() { delete[] elem; }  // destructor: free memory

        MyVector(const MyVector&);        // copy constructor
        MyVector& operator=(const MyVector&);       // copy assignment

        MyVector(MyVector&& vec);           // move constructor
        MyVector& operator=(MyVector&&);    // move assignment
        
        int size() const { return sz; }
        int capacity() const { return space; }

        void resize(int newsize, T val = T());           // growth
        void push_back(T& d);
        void reserve(int newalloc);

        T& operator[](int n) { return elem[n]; }        // access: return reference
        T operator[](int n) const { return elem[n]; }   // for const vectors 
};
