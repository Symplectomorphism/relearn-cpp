// a very simplified vector of doubles (like vector<double>)
class MyVector {
    int sz;                             // the size
    double* elem;                       // the pointer to the first element (of
                                        // type double)
    public: 
        MyVector(int s);                // constructor: allocate s doubles, 
                                        // let elem point to them
                                        // store s in sz
        int size() const { return sz; } // the current size
};
