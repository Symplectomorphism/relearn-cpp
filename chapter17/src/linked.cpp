#include "std_lib_facilities.h"
#include "MyVector.h"


class Link {
    public: 
        string value;
        Link(const string& v, Link* p=nullptr, Link* s=nullptr)
            : value{v}, prev{p}, succ{s} {}
        
        Link* insert(Link* n);              // insert n before this object
        Link* add(Link* n);                 // insert n after this object
        Link* erase();                      // remove this object from list
        Link* find(const string& s);        // find s in list
        const Link* find(const string& s) const;    // find s in const list

        const Link* advance(int n) const;         // move n positions in list

        Link* next() const { return succ; }
        Link* previous() const { return prev; }

    private:
        Link* prev;
        Link* succ;
};

Link* Link::insert(Link* n)      // insert n before p; return n
{
    if (!n) return this;
    // if (this==nullptr) return n;
    n->succ = this;        // p comes after n
    if (prev) prev->succ = n;  // n comes after what used to be p's predecessor
    n->prev = prev;  // p's predecessor becomes n's predecessor
    prev = n;        // n becomes p's predecessor
    return n;
}

Link* Link::add(Link* n)         // insert n after p; return n
{
    if (!n) return this;
    n->prev = this;
    if (succ) succ->prev = n;
    n->succ = succ;
    succ = n;
    return n;
}

Link* Link::erase()                // remove *p from list; return p's successor
{
    // if (!this) return nullptr;
    if (succ) succ->prev = prev;
    if (prev) prev->succ = succ;
    return succ;
}

Link* Link::find(const string& s)    // find s in list;
                                        // return nullptr for "not found"
{
    Link* p = this;
    while (p) {
        if (p->value == s) return p;
        p = p->succ;
    }
    return nullptr;
}

const Link* Link::advance(int n) const          // move n positions in the list
                                        // return nullptr for "not found"
                                        // +ve n moves forward, -ve backward
{
    // if (!this) return nullptr;
    const Link* p = this;
    if (0<n) {
        while (n--) {
            if (p->succ == nullptr) return nullptr;
            p = p->succ;
        }
    }
    else if (n<0) {
        while (n++) {
            if (p->prev == nullptr) return nullptr;
            p = p->prev;
        }
    }
    return p;
}

void print_all(Link* p)
{
    cout << "{ ";
    while (p) {
        cout << p->value;
        p = p->next();
        if (p) cout <<", ";
    }
    cout << " }";
}

int main() {
    // Link* norse_gods = new Link {"Thor", nullptr, nullptr};
    // norse_gods = new Link {"Odin", nullptr, norse_gods};
    // norse_gods->succ->prev = norse_gods;
    // norse_gods = new Link {"Freia", nullptr, norse_gods};
    // norse_gods->succ->prev = norse_gods;
    Link* norse_gods = new Link {"Thor"};
    norse_gods = norse_gods->insert(new Link {"Odin"});
    norse_gods = norse_gods->insert(new Link {"Zeus"});
    norse_gods = norse_gods->insert(new Link {"Freia"});

    Link* greek_gods = new Link {"Hera"};
    greek_gods = greek_gods->insert(new Link {"Athena"});
    greek_gods = greek_gods->insert(new Link {"Mars"});
    greek_gods = greek_gods->insert(new Link {"Poseidon"});

    Link* p =greek_gods->find("Mars");
    if (p) p->value = "Ares";

    p = norse_gods->find("Zeus");
    if (p) {
        if (p==norse_gods) norse_gods = p->next();
        p->erase();
        greek_gods = greek_gods->insert(p);
    }


    print_all(norse_gods);
    cout << "\n";
    
    print_all(greek_gods);
    cout << "\n";

    cout << p->advance(3)->value << "\n";

    return 0;
}
