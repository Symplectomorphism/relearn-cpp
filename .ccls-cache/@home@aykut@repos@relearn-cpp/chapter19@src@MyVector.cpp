#include "MyVector.h"
#include <cstdlib>

MyVector::MyVector(int s)
    : sz{s}, elem{new double[s]}, space{s}
{
    for (int i=0; i<s; ++i) elem[i]=0;
}

MyVector::MyVector(std::initializer_list<double> lst)
    :sz{static_cast<int>(lst.size())}, elem{new double[sz]}, 
     space{static_cast<int>(lst.size())}
{
    std::copy( lst.begin(), lst.end(), elem );
}

MyVector::MyVector(const MyVector& vector)
    :sz{vector.sz}, elem{new double[vector.sz]},space{vector.space}
{
    std::copy(vector.elem, vector.elem+sz, elem);
}

MyVector& MyVector::operator=(const MyVector& vec)
    // like copy constructor; but we must deal with old elements
{
    if (this == &vec) return *this;                 // self-assignment, no work needed
    
    if (vec.sz <= space) {                          // enough space, no need for new allocation
        for (int i=0; i<vec.sz; ++i) elem[i] = vec.elem[i]; // copy elements
        sz = vec.sz;
        return *this;
    }

    double* p = new double[vec.sz];                 // allocate new space
    for(int i=0; i<vec.sz; ++i) p[i] = vec.elem[i]; // copy elements
    delete [] elem;                                 // deallocate old space
    space = sz = vec.sz;                            // set new size
    elem = p;                                       // set new elements
    return *this;                                   // return a self-reference
}

MyVector::MyVector(MyVector&& vec)
    :sz{vec.sz}, elem{vec.elem}, space{vec.space} // copy vec's elem and sz
{
    vec.sz = 0;
    vec.elem = nullptr; 
    vec.space = 0;
}

MyVector& MyVector::operator=(MyVector&& vec)   // move vec to this vector
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

void MyVector::reserve(int newalloc)
{
    if (newalloc<=space) return;                // never decrease allocation
    double* p = new double[newalloc];           // allocate new space
    for (int i=0; i<sz; ++i) p[i] = elem[i];    // copy old elements
    delete[] elem;                              // deallocate old space
    elem = p;
    space = newalloc;
}

void MyVector::resize(int newsize)
    // make the vector have newsize elements
    // initialize each new element with the default value 0.0
{
    reserve(newsize);
    for (int i=sz; i<newsize; ++i) elem[i] = 0; // initialize new elements
    sz = newsize;
}

void MyVector::push_back(double d)
    // increase vector size by one; initialize the new element with d
{
    if (space==0)
        reserve(8);         // start with space for 8 elements
    else if (sz==space)
        reserve(2*space);   // get more space
    elem[sz] = d;           // add d at the end 
    ++sz;                   // increase the size (sz is the number of elements)
}
