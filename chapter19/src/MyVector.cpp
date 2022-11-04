/* Obsolete now!!!!!!!!! */
/* 
 
#include "MyVector.h"
#include <stdexcept>
#include <iostream>

// Default constructor
template<typename T, typename A>
MyVector<T,A>::MyVector(): sz{0}, elem{nullptr}, space{0}
{
    cout << "default constructor called!\n";
}

// Explicit constructor
template<typename T, typename A>
MyVector<T,A>::MyVector(int s)
    : sz{s}, elem{nullptr}, space{s}
{
    cout << "explicit constructor called!\n";
    elem = alloc.allocate(s);
    for (T* p = elem; p != elem + s; ++p) alloc.construct(p, 0);
}

// List constructor
template<typename T, typename A>
MyVector<T,A>::MyVector(std::initializer_list<T> lst)
    :sz{static_cast<int>(lst.size())}, elem{new T[sz]}, 
     space{static_cast<int>(lst.size())}
{
    std::copy( lst.begin(), lst.end(), elem );
}

// Copy constructor
template<typename T, typename A>
MyVector<T,A>::MyVector(const MyVector<T,A>& vec)
    :sz{vec.sz}, elem{nullptr},space{vec.sz}
{
    std::cout << "copy constructor called!\n";
    elem = alloc.allocate(vec.sz);
    std::copy(vec.elem, vec.elem+sz, elem);
}

// Copy assignment
template<typename T, typename A>
MyVector<T,A>& MyVector<T,A>::operator=(const MyVector<T,A>& vec)
    // like copy constructor; but we must deal with old elements
{
    std::cout << "copy assignment called!\n";
    if (this == &vec) return *this;                 // self-assignment, no work needed
    
    if (vec.sz <= space) {                          // enough space, no need for new allocation
        for (int i=0; i<vec.sz; ++i) elem[i] = vec.elem[i]; // copy elements
        for (int i=vec.sz; i<sz; ++i) alloc.destroy(&elem[i]);
        sz = vec.sz;
        return *this;
    }

    T* p = alloc.allocate(vec.sz);                // allocate new space
    std::copy(vec.elem, vec.elem+vec.sz, p);
    for (T* q = elem; q != elem+sz; ++q) alloc.destroy(q);
    alloc.deallocate(elem, space);
    // free(elem);
    space = sz = vec.sz;                            // set new size
    elem = p;                                       // set new elements
    return *this;                                   // return a self-reference
}

// Move constructor
template<typename T, typename A>
MyVector<T,A>::MyVector(MyVector<T,A>&& vec)
    :sz{vec.sz}, elem{vec.elem}, space{vec.space} // copy vec's elem and sz
{
    std::cout << "move constructor called!\n";
    vec.sz = 0;
    vec.elem = nullptr; 
    // vec.space = 0;
}

// Move assignment
template<typename T, typename A>
MyVector<T,A>& MyVector<T,A>::operator=(MyVector<T,A>&& vec)   // move vec to this vector
{
    std::cout << "move assignment called!\n";
    for (T* p = elem; p != elem+sz; ++p) alloc.destroy(p);
    alloc.deallocate(elem, space);
    // free(elem);
    elem = vec.elem;                        // copy vec's elem and sz
    sz = vec.sz;
    space = vec.space;
    vec.elem = nullptr;                     // make vec the empty vector
    vec.sz = 0;
    vec.space = 0;
    return *this;                           // return a self-reference
}

// Destructor
template<typename T, typename A>
MyVector<T,A>::~MyVector()
{
    cout << "destructor called!\n";
    for (T* p = elem; p != elem+sz; ++p) alloc.destroy(p);
    alloc.deallocate(elem, space);
    // free(elem);
}

// *******************************************************************************************
// range checking

template<typename T, typename A>
T& MyVector<T,A>::at(int n)
{
    if (n<0 || sz<=n) throw std::out_of_range("");
    return elem[n];
}

template<typename T, typename A> 
const T& MyVector<T,A>::at(int n) const
{
    if (n < 0 || sz < n) throw std::out_of_range("");
    return elem[n];
}


// *******************************************************************************************
// growth

template<typename T, typename A>
void MyVector<T,A>::reserve(int newalloc)
{
    if (newalloc<=space) return;                // never decrease allocation
    T* p = alloc.allocate(newalloc);           // allocate new space
    for (int i=0; i<sz; ++i) alloc.construct(&p[i], elem[i]);    // copy old elements
    for (int i=0; i<sz; ++i) alloc.destroy(&elem[i]);       // destroy
    alloc.deallocate(elem, space);              // deallocate old space
    // free(elem);
    elem = p;
    space = newalloc;
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

*/
