#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat *paolo = new Bureaucrat("Paolo", 150);
    Bureaucrat *giuseppe = new Bureaucrat("Giuseppe", 1);  
    
    try
	{
        // paolo->decrementGrade();
		//     std::cout << *paolo;
        // giuseppe->incrementGrade();
        //     std::cout << *giuseppe;
		paolo->incrementGrade();
		    std::cout << *paolo;
		giuseppe->decrementGrade();
		    std::cout << *giuseppe;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

    delete paolo;
    delete giuseppe;

    return (0);
}