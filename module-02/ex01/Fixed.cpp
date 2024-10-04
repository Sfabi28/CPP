#include "Fixed.hpp"

Fixed::Fixed() : fixedPointValue(0)
{
    std::cout << "Default constractor called" << std::endl;
}

Fixed::Fixed(const Fixed &Fixed) : fixedPointValue(Fixed.getRawBits())
{
    std::cout << "Copy constractor called" << std::endl;
}

Fixed::Fixed(const int value)
{
    std::cout << "int constructor called" << std::endl;
    fixedPointValue = value << fractionalBits;
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    fixedPointValue = roundf(value * (1 << fractionalBits));
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

std::ostream &operator <<  (std::ostream &ins, const Fixed &Fixed)
{
    ins << Fixed.toFloat();
    return ins;
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

float   Fixed::toFloat() const
{
    return (float)fixedPointValue / (1 << fractionalBits);
}

int     Fixed::toInt() const
{
    return fixedPointValue >> fractionalBits;
}
