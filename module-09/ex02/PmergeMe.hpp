#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <string>
# include <exception>
# include <vector>
# include <deque>
# include <ostream>
# include <algorithm>
# include <sstream>
# include <iostream>
# include <ctime>

class PmergeMe
{
    private:
        std::vector<int> vec;
        std::deque<int> deq;

    public:
        PmergeMe();
        PmergeMe(char **av);
        PmergeMe(const PmergeMe &copy);
        PmergeMe &operator=(const PmergeMe &copy);
        ~PmergeMe();

        class NotValidNumber : public std::exception
        {
            public:
                const char *what() const throw();
        };

        template <class T>
        void merge(T &container);

        template <class T>
        bool issorted(T &container);
};

#endif