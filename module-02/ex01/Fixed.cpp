#include "Fixed.hpp"

Fixed::Fixed() : fixedPointValue(0)
{
    std::cout << "Default constractor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) : fixedPointValue(fixed.getRawBits())
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

Fixed &Fixed::operator = (const Fixed &fixed)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &fixed)
        this->fixedPointValue = fixed.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

std::ostream &operator <<  (std::ostream &ins, const Fixed &fixed)
{
    ins << fixed.toFloat();
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
