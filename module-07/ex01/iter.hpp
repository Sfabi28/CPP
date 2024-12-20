#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <class T> void iter(T *arr, size_t len, void (*f)(T))
{
    size_t i = 0;

    while (i < len)
    {
        f(arr[i]);
        i++;
    }
}

template <class T> void print(T a)
{
    std::cout << a << std::endl;
}

#endif