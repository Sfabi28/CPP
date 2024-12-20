#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat *paolo = new Bureaucrat("Paolo", 150);
    Bureaucrat *giuseppe = new Bureaucrat("Giuseppe", 1);  
	Form *c14 = new Form("c14", 20, 20);
    
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
		paolo->signForm(*c14);
		giuseppe->signForm(*c14);
		giuseppe->signForm(*c14);

	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

    delete paolo;
    delete giuseppe;
	delete c14;

    return (0);
}