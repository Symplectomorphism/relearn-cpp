#include <iostream>
#include <string>

template<class Iterator>
void advance(Iterator& p, int n)
{
    if (n > 0)
        while (n > 0) { 
			++p; 
			--n;
		}
    else if (n < 0)
        while (n < 0) {
			--p;
			++n;
		}
}

int main()
{
	try 
	{
		std::string s("Iterator");
		std::string::iterator s_iter = s.begin();

		std::cout << *s_iter <<'\n';

		advance(s_iter, 2);

		std::cout << *s_iter <<'\n';

		advance(s_iter, -2);

		std::cout << *s_iter <<'\n';
	} 
	catch (std::exception& e) 
	{
		std::cerr << e.what();
	}
	getchar ();
}
