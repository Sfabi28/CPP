#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <exception>

class ValueNotFound : public std::exception
{
	public:
		virtual const char *what() const throw()
		{
			return "Value not found";
		}
};

template <class T> T easyfind(std::vector <T> &vect, int toSearch)
{
    for (size_t i = 0; i < vect.size(); i++)
    {
        if (vect.at(i) == toSearch)
            return vect.at(i);
    }
    throw ValueNotFound();
};


#endif