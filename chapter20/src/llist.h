#include <iostream>

#ifndef llist_h
#define llist_h

template <typename Elem>
struct Link
{
    Link* succ;
    Link* prev;
    Elem val;
    Link (const Elem& v = Elem{0}, Link<Elem>* p = nullptr, Link<Elem>* s = nullptr)
        : val(v), prev(p), succ(s) {  }
};

//------------------------------------------------------------------------

template<typename Elem>
class List {
    public: 
        class iterator;

        List()
            : sz{0}, first(new Link<Elem>{}), last{first} { }

        explicit List( int n, Elem def=Elem() )
            : sz{n}, first{new Link<Elem>{}}, last{first}
        {
            for (int i=0; i<n; ++i) {
                first = new Link<Elem>{def, nullptr, first};
                first->succ->prev = first;
            }
        }

        ~List()
        {
            while (first != nullptr) {
                auto p = first->succ;
                delete first;
                first = p;
            }
        }

        iterator begin() { return iterator{first}; }
        iterator end() { return iterator{last}; }

        iterator insert( iterator p, const Elem& v );
        // iterator erase( iterator p );

        void push_back( const Elem& v );
        void push_front( const Elem& v ); 
        
        void print();

        /*

        void pop_front();
        void pop_back();

        Elem& front() { return first->val; }
        Elem& back();

        */

        int size() const { return sz; }

    private:
        int sz;
        Link<Elem> *first;
        Link<Elem> *last;
};

//------------------------------------------------------------------------

template<typename Elem>
class List<Elem>::iterator
{
    public:
        iterator( Link<Elem>* p ) : curr{p} { }

        iterator& operator++()  { curr = curr->succ; return *this; }
        iterator& operator--()  { curr = curr->prev; return *this; }
        Elem& operator*() { return curr->val; }
        Link<Elem>* operator->() { return curr; }

        bool operator==(const iterator& b) { return curr == b.curr; }
        bool operator!=(const iterator& b) { return curr != b.curr; }

    private: 
        Link<Elem>* curr;
};

template<typename Elem>
typename List<Elem>::iterator List<Elem>::insert(List<Elem>::iterator p, const Elem& v)
{
    Link<Elem>* q = new Link<Elem>{v, p->prev};

    if (p->succ) q->succ = p->succ->prev;
    else q->succ = last;
    p->prev = q;

    if (q->prev) q->prev->succ = q;
    else first = q;

    ++sz;
    return iterator{q};
}

template<typename Elem>
void List<Elem>::push_front(const Elem& v)
{
    Link<Elem>* p = new Link<Elem> {v};
    p->succ = first;
    first->prev = p;
    first = p;
    ++sz;
}

template<typename Elem>
void List<Elem>::push_back(const Elem& v)
{
    Link<Elem>* p = new Link<Elem> {v};

    if (last == first) first = p;
    else last->prev->succ = p;

    p->prev = last->prev;
    p->succ = last;
    last->prev = p;
    ++sz;
}

template<typename Elem>
void List<Elem>::print()
{
    for (iterator p=begin(); p!=end(); ++p)
        std::cout << *p << " ";
    std::cout << "\n";
}

template<typename Iterator>
Iterator high ( Iterator first, Iterator last )
{
    Iterator high = first;
    for (Iterator p=first; p!=last; ++p)
        if (*high < *p) high = p;
    return high;
}

#endif
