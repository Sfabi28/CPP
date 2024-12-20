#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <stdint.h>
#include "Data.hpp"

class Data;

class Serializer
{
    public:
        Serializer();
        Serializer(const Serializer &copy);
        Serializer &operator = (const Serializer &copy);
        virtual ~Serializer() = 0;
    
        static uintptr_t serialize(Data *ptr);
        static Data *deserialize(uintptr_t raw);
};

#endif