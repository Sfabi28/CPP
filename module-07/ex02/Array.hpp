#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>
# include <ctime>
# include <cstdlib>

template <class T> class Array
{
    private:
        T *arr;
        unsigned int _size;
    
    public:
        Array() : arr(NULL), _size(0) {}

        Array(unsigned int n) : _size(n)
        {
            arr = new T[n];
        }

        Array(const Array &copy) : _size(copy._size)
        {
            arr = new T[copy._size];
            for (unsigned int i = 0; i < copy._size; i++)
                arr[i] = copy.arr[i];
        }

        Array &operator = (const Array &copy)
        {
            if (this != &copy)
            {
                delete [] arr;
                arr = new T[copy._size];
                _size = copy._size;
                for (int i = 0; i < copy._size; i++)
                    arr[i] = copy.arr[i];
            }
            return (*this);
        }

        ~Array()
        {
            delete [] arr;
        }

        T &operator[](unsigned int index)
        {
            if (index >= this->_size)
                throw std::exception();
            return arr[index];
        }

        unsigned int size()
        {
            return (this->_size);
        }

};

#endif