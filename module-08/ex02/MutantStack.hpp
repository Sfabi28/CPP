#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <string>
# include <exception>
# include <stack>

template <class T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack()
        {
            std::stack<T>();
        }
        MutantStack(const MutantStack &copy) : std::stack<T>(copy){}
        MutantStack &operator = (const MutantStack &copy)
        {
            if (this != &copy)
                std::stack<T>::operator=(copy);
            return (*this);
        }
        ~MutantStack() {};

        typedef class std::stack <T>::container_type::iterator iterator;

        iterator begin()
        {
            return (std::stack<T>::c.begin());
        }
        iterator end()
        {
            return (std::stack<T>::c.end());
        }
};

#endif