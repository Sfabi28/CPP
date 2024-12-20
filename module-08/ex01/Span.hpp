#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <exception>
# include <algorithm>
# include <climits>

class Span
{
    private:
        unsigned int N;
        std::vector <int> vect;
    
    public:
        Span();
        Span(const Span &copy);
        Span &operator = (const Span &copy);
        ~Span();

        Span(unsigned int nbr);

        void addNumber(int nbr);
        size_t shortestSpan();
        size_t longestSpan();
        void addNumbers(int *nbrs, int size);

    class VectorFull : public std::exception
    {
	public:
		virtual const char *what() const throw()
		{
			return "vector full";
		}
    };

    class TooFewNumbers : public std::exception
    {
	public:
		virtual const char *what() const throw()
		{
			return "too few numbers";
		}
    };
};

#endif