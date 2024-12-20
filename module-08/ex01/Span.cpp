#include "Span.hpp"

Span::Span() : N(10) {}

Span::Span(const Span &copy) : N(copy.N), vect(copy.vect) {}

Span &Span::operator = (const Span &copy)
{
    if (this != &copy)
    {
        N = copy.N;
        vect = copy.vect;
    }
    return (*this);
}

Span::~Span() {}

Span::Span(unsigned int nbr) : N(nbr) {}

void Span::addNumber(int nbr)
{
    if (vect.size() == this->N)
        throw VectorFull();
    vect.push_back(nbr);
}

size_t Span::shortestSpan()
{
    if (vect.size() < 2)
        throw TooFewNumbers();

    std::sort(vect.begin(), vect.end());
    std::vector<int>::iterator it = vect.begin();

    int diff = INT_MAX;
    
    for (it = vect.begin(); it != vect.end() - 1; ++it)
    {
        int current_diff = *(it + 1) - *it;
        if (current_diff < diff)
            diff = current_diff;
    }
    return (static_cast<size_t>(diff));
}

size_t Span::longestSpan()
{
    if (vect.size() < 2)
        throw TooFewNumbers();

    std::sort(vect.begin(), vect.end());
    return ((vect[vect.size() - 1] - vect[0]));
}

void Span::addNumbers(int *nbrs, int size)
{
    try
    {
        for (int i = 0; i < size; i++)
            addNumber(nbrs[i]);
    }
    catch (VectorFull &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

