#include "Span.hpp"

int main()
{
    int size = 10000;
    Span pancetta(size);
    int arr[size];

    srand(static_cast<unsigned>(time(0)));

    for(int i = 0; i < size; i++)
    {
        if (rand() % 2)
            arr[i] = - (rand() % 600000000);
        else
            arr[i] = rand() % 600000000;

        //std::cout << arr[i] << std::endl;
    }

    pancetta.addNumbers(arr, size);
    
    std::cout << "shortest span: " << pancetta.shortestSpan() << std::endl;
        std::cout << "longest span: " << pancetta.longestSpan() << std::endl;
    return 0;
}