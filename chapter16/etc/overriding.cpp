#include <iostream>

struct B {
    virtual void f() const { std::cout << "B::f "; }
    void g() const { std::cout << "B::g "; }              // not virtual
};

struct D : B {
    void f() const override { std::cout << "D::f "; }      // overrides B::f
    void g() const { std::cout << "D::g "; }
};

struct DD : D {
    void f() const override { std::cout << "DD::f "; }    // doesn't override D::f
                                                        // (not const)
    void g() const { std::cout << "DD::g "; } 
};

void call(const B& b)
    // a D is a kind of B, so call() can accept a D
    // a DD is a kind of D and a D is a kind of B, so call() can accept a DD
{
    b.f();
    b.g();
}

int main () {
    B b;
    D d;
    DD dd;

    call(b);
    call(d);
    call(dd);

    b.f();
    b.g();

    d.f();
    d.g();

    dd.f();
    dd.g();
}
