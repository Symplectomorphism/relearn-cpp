// a very simplified vector of doubles (like vector<double>)
class MyVector {
    int sz;                             // the size
    double* elem;                       // the pointer to the first element (of
                                        // type double)
    public: 
        MyVector(int s):                // constructor
            sz{s},                      // initialize sz
            elem{new double[s]}         // initialize elem 
            {
                for (int i=0; i<s; ++i) elem[i]=0;          // initialize elements
            }        
        ~MyVector() { delete[] elem; }  // destructor: free memory
        
        int size() const { return sz; } // the current size

        double get(int n) const { return elem[n]; }
        void set(int n, double v) { elem[n] = v; }
};
