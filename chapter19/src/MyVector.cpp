#include "MyVector.h"
#include <cstdlib>

template<typename T, typename A>
MyVector<T,A>::MyVector(int s)
    : sz{s}, elem{new T[s]}, space{s}
{
    for (int i=0; i<s; ++i) elem[i]=0;
}

template<typename T, typename A>
MyVector<T,A>::MyVector(std::initializer_list<T> lst)
    :sz{static_cast<int>(lst.size())}, elem{new T[sz]}, 
     space{static_cast<int>(lst.size())}
{
    std::copy( lst.begin(), lst.end(), elem );
}

template<typename T, typename A>
MyVector<T,A>::MyVector(const MyVector<T,A>& vector)
    :sz{vector.sz}, elem{new T[vector.sz]},space{vector.space}
{
    std::copy(vector.elem, vector.elem+sz, elem);
}

template<typename T, typename A>
MyVector<T,A>& MyVector<T,A>::operator=(const MyVector<T,A>& vec)
    // like copy constructor; but we must deal with old elements
{
    if (this == &vec) return *this;                 // self-assignment, no work needed
    
    if (vec.sz <= space) {                          // enough space, no need for new allocation
        for (int i=0; i<vec.sz; ++i) elem[i] = vec.elem[i]; // copy elements
        sz = vec.sz;
        return *this;
    }

    T* p = new T[vec.sz];                 // allocate new space
    for(int i=0; i<vec.sz; ++i) p[i] = vec.elem[i]; // copy elements
    delete [] elem;                                 // deallocate old space
    space = sz = vec.sz;                            // set new size
    elem = p;                                       // set new elements
    return *this;                                   // return a self-reference
}

template<typename T, typename A>
MyVector<T,A>::MyVector(MyVector<T,A>&& vec)
    :sz{vec.sz}, elem{vec.elem}, space{vec.space} // copy vec's elem and sz
{
    vec.sz = 0;
    vec.elem = nullptr; 
    vec.space = 0;
}

template<typename T, typename A>
MyVector<T,A>& MyVector<T,A>::operator=(MyVector<T,A>&& vec)   // move vec to this vector
{
    delete[] elem;                          // deallocate old space
    elem = vec.elem;                        // copy vec's elem and sz
    sz = vec.sz;
    space = vec.space;
    vec.elem = nullptr;                     // make vec the empty vector
    vec.sz = 0;
    vec.space = 0;
    return *this;                           // return a self-reference
}

template<typename T, typename A>
void MyVector<T,A>::reserve(int newalloc)
{
    if (newalloc<=space) return;                // never decrease allocation
    T* p = alloc.allocate(newalloc);           // allocate new space
    for (int i=0; i<sz; ++i) alloc.construct(&p[i], elem[i]);    // copy old elements
    for (int i=0; i<sz; ++i) alloc.destroy(&elem[i]);       // destroy
    alloc.deallocate(elem, space);              // deallocate old space
    elem = p;
    space = newalloc;
}

template<typename T, typename A>
void MyVector<T,A>::resize(int newsize, T val)
    // make the vector have newsize elements
    // initialize each new element with the default value 0.0
{
    reserve(newsize);
    for (int i=sz; i<newsize; ++i) alloc.construct(&elem[i], val); // initialize new elements
    for (int i=newsize; i<sz; ++i) alloc.destroy(&elem[i]);
    sz = newsize;
}

template<typename T, typename A>
void MyVector<T,A>::push_back(T& d)
    // increase vector size by one; initialize the new element with d
{
    if (space==0)
        reserve(8);         // start with space for 8 elements
    else if (sz==space)
        reserve(2*space);   // get more space
    alloc.construct(&elem[sz], d);  // add d at the end 
    ++sz;                   // increase the size (sz is the number of elements)
}

struct No_default {
    No_default(int);
};

int main()
{
    MyVector<double>v1;
    v1.resize(100);
    v1.resize(200, 0.0);
    v1.resize(300, 1.0);

    // MyVector<No_default> v2(10);
    MyVector<No_default> v3;
    // v3.resize(100, No_default(2));
    // v3.resize(200);
}
