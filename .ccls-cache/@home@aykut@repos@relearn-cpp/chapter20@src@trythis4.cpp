#include <iostream>
#include <vector>

double* get_from_jack(int* count)
{
    return new double;
}

std::vector<double>* get_from_jill()
{
    return new std::vector<double>();
}

template<typename Iterator>
Iterator high(Iterator first, Iterator last)
    // return an iterator to the element in [first:last) that has the highest
    // value
{
    if (!first || !last)
        throw std::invalid_argument("high: null pointer argument!\n");

    Iterator high = first;
    for (Iterator p = first; p!=last; ++p)
        if (*high<*p) high = p;
    return high;
}

void fct()
{
    int jack_count = 0;
    double* jack_data = get_from_jack(&jack_count);

    if (!jack_data)
    {
        delete[] jack_data;
        throw std::runtime_error("fct: null pointer returned!\n");
    }

    std::vector<double>* jill_data = get_from_jill();
    
    if (!jill_data)
    {
        delete[] jack_data;
        delete jill_data;
        throw std::runtime_error("fct: null pointer returned!\n");
    }
    std::vector<double>& v = *jill_data;

    double* jack_high = nullptr;
    double* jill_high = nullptr;
    
    try {
        jack_high = high(jack_data, jack_data+jack_count);
        jill_high = high(&v[0], &v[0]+v.size());
    }
    catch (std::invalid_argument& i){
        throw std::runtime_error(i.what());
    }

    std::cout << "Jill's high" << *jill_high << "; Jack's high " << *jack_high;
    // ...
    delete[] jack_data;
    delete jill_data;
}

int main()
try{

}
catch(std::exception& e)
{
    std::cerr << e.what();
    return 1;
}
catch(...)
{
    return 2;
}
