#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
	for (int i = 5; i > 0; i--)
	{
		std::cout << "\033[9" << i << "m";
		std::cout << "Generate: " << 6 - i<< std::endl;
		Base * base = generate();
		std::cout << "Identify from pointer: " <<6 - i<< std::endl;
		identify(base);
		std::cout << "Identify from reference: " <<6 - i<< std::endl;
		identify(*base);
		delete base;
	}	
	return 0;
}