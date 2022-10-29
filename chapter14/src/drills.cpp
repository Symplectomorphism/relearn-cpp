#include <iostream>

using namespace std;

class B1 {
    public:
       virtual void vf() const { cout << "B1::vf()\n"; } 
       void f() const { cout << "B1:f()\n"; }
       virtual void pvf() = 0;
};

class D1 : public B1 {
    public:
        void vf() const { cout << "D1::vf()\n"; }
        void f() const { cout << "D1:f()\n"; }
};

class D2 : public D1 {
    public:
        void pvf() override { cout << "D2::pvf()\n"; }
};

class B2 {
    public: 
        virtual void pvf() = 0;
};

class D21 : public B2 {
    public:
        void pvf() override { cout << "s\n"; }
    private:
        string s = "contents";
};

class D22 : public B2 {
    public:
        void pvf() override { cout << n << "\n"; }
    private:
        int n = 42;
};

void f ( B2& b ) {
    b.pvf();
}

int main() {
    // B1 b;

    // b.vf();
    // b.f();

    // D1 d;

    // d.vf();
    // d.f();

    /* Trying to understand upcasting 
     * Explained here:
     * https://stackoverflow.com/questions/22504496/c-will-virtual-functions-still-work-if-i-upcast-a-derived-object-to-its-base-t
     */
    // B1& r {d};
    // 
    // r.vf();
    // r.vf();
    
    // B1* r = &d;

    // (*r).vf();
    // (*r).f();

    // printf("%p\n", &r);
    // printf("%p\n", &d);

    D2 d;

    d.f();
    d.vf();
    d.pvf();

    D21 two_one;
    D22 two_two;

    f( two_one );
    f( two_two );

    return 0;
}
