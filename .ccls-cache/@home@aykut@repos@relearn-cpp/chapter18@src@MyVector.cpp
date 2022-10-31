#include "MyVector.h"
#include <cstdlib>

MyVector::MyVector(int s)
    : sz{s}, elem{new double[s]}
{
    for (int i=0; i<s; ++i) elem[i]=0;
}

MyVector::MyVector(std::initializer_list<double> lst)
    :sz{static_cast<int>(lst.size())}, elem{new double[sz]}
{
    std::copy( lst.begin(), lst.end(), elem );
}

MyVector::MyVector(const MyVector& vector)
    :sz{vector.sz}, elem{new double[vector.sz]}
{
    std::copy(vector.elem, vector.elem+sz, elem);
}

MyVector& MyVector::operator=(const MyVector& vec)
    // make this vector a copy of vec
{
    double* p = new double[vec.sz];         // allocate new space
    std::copy(vec.elem, vec.elem+sz, p);    // copy elements
    delete [] elem;                         // deallocate old space
    elem = p;                               // now we can reset elem
    sz = vec.sz;
    return *this;                           // return a self-reference
}

MyVector::MyVector(MyVector&& vec)
    :sz{vec.sz}, elem{vec.elem}             // copy vec's elem and sz
{
    vec.sz = 0;
    vec.elem = nullptr; 
}

MyVector& MyVector::operator=(MyVector&& vec)   // move vec to this vector
{
    delete[] elem;                          // deallocate old space
    elem = vec.elem;                        // copy vec's elem and sz
    sz = vec.sz;
    vec.elem = nullptr;                     // make vec the empty vector
    vec.sz = 0;
    return *this;                           // return a self-reference
}
