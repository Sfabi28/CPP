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
        MutantStack(const MutantStack &copy) : std::stack<T>(copy.std::stack<T>){}
        MutantStack &operator = (const MutantStack &copy)
        {
            
        }
        ~MutantStack();

        typedef class std::stack <T>::container_type::iterator it = stack.top();
        typedef class std::stack <T>::container_type::iterator ite;

};

#endif