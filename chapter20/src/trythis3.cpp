#include <iostream>
#include <stdexcept>

void copy(int* f1, int* e1, int* f2)
{
    if( !f1 || !e1 || !f2 )
        throw std::invalid_argument("copy:: null pointer argument!\n");

    int* iter_dest = f2;
    for (int* iter_src = f1; iter_src != e1; ++iter_src) {
        *iter_dest = *iter_src;
        ++iter_dest;
    }
}


int main()
try{
    const int size = 5;
    int src[size] {1, 2, 3, 4, 5};
    int* dest = new int[size];

    int* beg_src = &src[0];
    int* end_src = &src[size];

    copy(beg_src, end_src, dest);

    for (int i=0; i<size; ++i)
        std::cout << dest[i] << " ";
    std::cout << "\n";
}
catch (std::exception& e)
{
    std:: cerr << e.what();
    return 1;
}
catch (...)
{
    return 2;
}
