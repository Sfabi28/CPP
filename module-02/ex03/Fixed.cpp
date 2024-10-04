#include "Fixed.hpp"

Fixed::Fixed() : fixedPointValue(0)
{
   // std::cout << "Default constractor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) : fixedPointValue(fixed.getRawBits())
{
    //std::cout << "Copy constractor called" << std::endl;
}

Fixed::Fixed(const int value)
{
   // std::cout << "int constructor called" << std::endl;
    fixedPointValue = value << fractionalBits;
}

Fixed::Fixed(const float value)
{
  //  std::cout << "Float constructor called" << std::endl;
    fixedPointValue = roundf(value * (1 << fractionalBits));
}

Fixed &Fixed::operator = (const Fixed &fixed)
{
  //  std::cout << "Copy assignment operator called" << std::endl;
    if (this != &fixed)
        this->fixedPointValue = fixed.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
   // std::cout << "Destructor called" << std::endl;
}

std::ostream &operator <<  (std::ostream &ins, const Fixed &fixed)
{
    ins << fixed.toFloat();
    return ins;
}

int Fixed::getRawBits(void) const
{
    //std::cout << "getRawBits member function called" << std::endl;
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

bool    Fixed::operator > (const Fixed &fixed)
{
    float first = this->toFloat();
    float second = fixed.toFloat();
    if (first > second)
        return true;
    return false;
}

bool    Fixed::operator < (const Fixed &fixed)
{
    float first = this->toFloat();
    float second = fixed.toFloat();
    if (first < second)
        return true;
    return false;
}

bool    Fixed::operator >= (const Fixed &fixed)
{
    float first = this->toFloat();
    float second = fixed.toFloat();
    if (first >= second)
        return true;
    return false;
}

bool    Fixed::operator <= (const Fixed &fixed)
{
    float first = this->toFloat();
    float second = fixed.toFloat();
    if (first <= second)
        return true;
    return false;
}

bool    Fixed::operator == (const Fixed &fixed)
{
    int first = this->toInt();
    int second = fixed.toInt();
    if (first == second)
        return true;
    return false;
}

bool    Fixed::operator != (const Fixed &fixed)
{
    int first = this->toInt();
    int second = fixed.toInt();
    if (first != second)
        return true;
    return false;
}

Fixed   Fixed::operator + (const Fixed &fixed)
{
    float first = this->toFloat();
    float second = fixed.toFloat();
    Fixed ret(first + second);
    return (ret);
}

Fixed   Fixed::operator - (const Fixed &fixed)
{
    float first = this->toFloat();
    float second = fixed.toFloat();
    Fixed ret(first - second);
    return (ret);
}

Fixed   Fixed::operator * (const Fixed &fixed)
{
    float first = this->toFloat();
    float second = fixed.toFloat();
    Fixed ret(first * second);
    return (ret);
}

Fixed   Fixed::operator / (const Fixed &fixed)
{
    float first = this->toFloat();
    float second = fixed.toFloat();
    Fixed ret(first / second);
    return (ret);
}

Fixed   &Fixed::operator ++ (void)
{
    fixedPointValue++;
    return (*this);
}

Fixed   &Fixed::operator -- (void)
{
    fixedPointValue--;
    return (*this);
}

Fixed   Fixed::operator ++ (int)
{
    Fixed tmp(*this);
	operator++();
	return (tmp); 
}

Fixed   Fixed::operator -- (int)
{
    Fixed tmp(*this);
	operator--();
	return (tmp); 
}

Fixed   Fixed::min(Fixed &a, Fixed &b)
{
    if (a < b)
        return (a);
    return (b);
}

Fixed   Fixed::min(const Fixed &a, const Fixed &b)
{
    Fixed tmp = a;
    if (tmp < b)
        return (a);
    return (b);
}

Fixed   Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return (a);
    return (b);
}

Fixed   Fixed::max(const Fixed &a, const Fixed &b)
{
    Fixed tmp = a;
    if (tmp > b)
        return (a);
    return (b);
}






