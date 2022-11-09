#ifndef llist_h
#define llist_h

template <typename Elem>
struct Link
{
    Link()
        : succ(nullptr), prev(nullptr), val(Elem()) {  }

    Link ( Link<Elem>* s, Link<Elem>* p, const Elem& v = Elem() )
        : succ(s), prev(p), val(v) {  }

    Link ( const Link<Elem>& src ) 
        : succ(src.succ), prev(src.prev), val(src.val) {  }

    Link<Elem>& operator= ( const Link<Elem>& src )
    {
        Link<Elem> temp{src};
        swap(temp);
        return *this;
    }

    void swap(Link<Elem>& src)
    {
        Link<Elem> temp{src};

        src.succ = succ;
        src.prev = prev;
        src.val = val;

        succ = temp.succ;
        prev = temp.prev;
        val = temp.val;
    }

    Link* succ;
    Link* prev;
    Elem val;
};

template<typename Elem>
void swap (Link<Elem>& lhs, Link<Elem>& rhs)
{
    lhs.swap(rhs);
}

//------------------------------------------------------------------------

template<typename Elem>
class List {
    public: 
        class iterator;

        List()
            : first(new Link<Elem>()), last(first) { }

        iterator begin();
        iterator end();

        iterator insert( iterator p, const Elem& v );
        iterator erase( iterator p );

        void push_back( const Elem& v );
        void push_front( const Elem& v ) { first = new Link<Elem>{first, nullptr, v}; }
        void pop_front();
        void pop_back();

        Elem& front() { return first->val; }
        Elem& back();

    private:
        Link<Elem> *first;
        Link<Elem> *last;
};

//------------------------------------------------------------------------

template<typename Elem>
class List<Elem>::iterator
{

};

#endif
