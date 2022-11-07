#include <iostream>

template <typename Iter, typename T>
Iter find(Iter first, Iter last, const T& val)
{
    while ( first!=last && *first!=val ) ++first;
    return first;
}

template <typename Iter, typename T>
Iter find2(Iter first, Iter last, const T& val)
{
    for (Iter p=first; p!=last; ++p)
        if ( *p==val ) return p;
    return first;
}

int main()
try {
    const size_t size = 10;
    int arr[size] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    int target = 0;

    int* found = find(arr, arr+size, target);
    int* found2 = find2(arr, arr+size, target);

    if (found != arr+size)
        std::cout << "Target: " << *found << "\n";
    else
        std::cout << "Not found!\n";

    if (found2 != arr+size)
        std::cout << "Target: " << *found2 << "\n";
    else
        std::cout << "Not found!\n";

    return 0;
}
catch(std::exception& e)
{
    std::cout << e.what() << "\n";
    return 1;
}
catch(...)
{
    std::cout << "unknown exception\n";
    return 2;
}
