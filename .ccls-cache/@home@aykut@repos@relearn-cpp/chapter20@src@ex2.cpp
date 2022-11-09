#include <iostream>
#include <fstream>
#include <vector>

double* get_from_jack(int* count)
{
    std::string file_name("ex2.txt");
    std::ifstream ifs(file_name.c_str());

    if (!ifs) 
        throw std::runtime_error("get_from_jack: can't open input stream.");

    const int size = *count;
    double* data = new double [size];
    int index = 0;

    if (!data)
        throw std::bad_alloc();

    double value;
    while ( index < size && ifs >> value )
    {
        data[index] = value;
        ++index;
    }

    return data;
}

std::vector<double>* get_from_jill()
{
    std::string file_name("ex2.txt");
    std::ifstream ifs(file_name.c_str());

    if (!ifs) 
        throw std::runtime_error("get_from_jill: can't open input stream.");

    std::vector<double>* data = new std::vector<double>;

    if (!data)
        throw std::bad_alloc();

    double value;
    while ( ifs >> value )
        data->push_back(value);

    return data;
}

double* high (double* first, double* last)
{
    if (!first || !last)
        throw std::invalid_argument("high: null pointer argument\n");

    double* high = first;
    for (double* p = first; p!=last; ++p)
        if (*high < *p) high = p;

    return high;
}

int main() 
{
    return 0;
}
