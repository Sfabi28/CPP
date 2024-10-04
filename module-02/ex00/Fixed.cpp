#include "Fixed.hpp"

Fixed::Fixed() : fixedPointValue(0)
{
    std::cout << "Default constractor called" << std::endl;
}

Fixed::Fixed(const Fixed &Fixed) : fixedPointValue(Fixed.getRawBits())
{
    std::cout << "Copy constractor called" << std::endl;
}

Fixed &Fixed::operator = (const Fixed &Fixed)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &Fixed)
        this->fixedPointValue = Fixed.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
    this->fixedPointValue = raw;
}