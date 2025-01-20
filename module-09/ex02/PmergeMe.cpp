#include "PmergeMe.hpp"

const char *PmergeMe::NotValidNumber::what() const throw()
{
	return "Not valid number";
}

PmergeMe::PmergeMe() : vec(0), deq(0)
{
    //std::cout << "Default constructor called" << std::endl;
}

PmergeMe::PmergeMe(char **av)
{
    //std::cout << "constructor called" << std::endl;
    std::stringstream ss;
	int nbr;

    for (int i = 1; av[i]; i++)
    {
        ss << av[i];
        ss >> nbr;
        if (ss.fail() || nbr < 0)
            throw NotValidNumber();
        vec.push_back(nbr);
        deq.push_back(nbr);
        ss.clear(); 
    }
}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
    //std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy)
{
    //std::cout << "Assignation operator called" << std::endl;
    if (this != &copy)
    {
        vec = copy.vec;
        deq = copy.deq;
    }
    return *this;
}

PmergeMe::~PmergeMe()
{
    //std::cout << "Destructor called" << std::endl;
}

template <class T>
bool PmergeMe::issorted(T &container)
{
    typename T::iterator it = container.begin();
    typename T::iterator it_next = container.begin();
    ++it_next;
    while (it_next != container.end())
    {
        if (*it > *it_next)
            return false;
        ++it;
        ++it_next;
    }
    return true;
}

template <class T>
void PmergeMe::merge(T &container)
{
    T temporary_small;
    T temporary_big;

    typename T::iterator it = container.begin();
    
    while (it != container.end()) // 1, 11, 10, 9, 2, 3, 5, 4, 8, 6, 7
    {
        typename T::iterator next_it = it;
        ++next_it;
        
        if (next_it != container.end())
        {
            if (*it > *next_it)
            {
                temporary_small.push_back(*next_it);
                temporary_big.push_back(*it);
            }
            else
            {
                temporary_small.push_back(*it);
                temporary_big.push_back(*next_it);
            }
            ++it;
            ++it;
        }
        else
        {
            temporary_small.push_back(*it);
            ++it;
        }
    }
    container.clear();
    if (!issorted(temporary_big))
        merge(temporary_big);
    else
    {
        for (typename T::iterator it = temporary_big.begin(); it != temporary_big.end(); ++it)
            container.push_back(*it);
        binarySearch(container, temporary small)//
    }
}

