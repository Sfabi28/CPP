#include "Fixed.hpp"

int main( void ) {
Fixed a;
Fixed b( Fixed( 5.05f ) * Fixed( 2 ) );
Fixed c( Fixed( 5.05f ) * Fixed( 2 ) );

std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;

std::cout << Fixed::min( a, b ) << std::endl;
std::cout << a + b << std::endl;
std::cout << a - b << std::endl;
std::cout << b - a << std::endl;
std::cout << a * b << std::endl;
std::cout << a / b << std::endl;
std::cout << Fixed( a ) << std::endl;
std::cout << Fixed( b ) << std::endl;

if (a < b)
std::cout << "a is less than b" << std::endl;
if (a > b)
std::cout << "a is greater than b" << std::endl;
if (a <= b)
std::cout << "a is less than or equal to b" << std::endl;
if (a >= b)
std::cout << "a is greater than or equal to b" << std::endl;
if (a == b)
std::cout << "a is equal to b" << std::endl;
if (a != b)
std::cout << "a is not equal to b" << std::endl;

if (c < b)
std::cout << "c is less than b" << std::endl;
if (c > b)
std::cout << "c is greater than b" << std::endl;
if (c <= b)
std::cout << "c is less than or equal to b" << std::endl;
if (c >= b)
std::cout << "c is greater than or equal to b" << std::endl;
if (c == b)
std::cout << "c is equal to b" << std::endl;
if (c != b)
std::cout << "c is not equal to b" << std::endl;

return 0;
}