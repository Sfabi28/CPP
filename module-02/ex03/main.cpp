
#include "Point.hpp"

int main( void ) {

    Point const a(0.0f, 0.0f);
    Point const b(4.0f, 0.0f);
    Point const c(0.0f, 4.0f);

	Point const p(10.0f, 10.0f);
	Point const q(1.0f, 1.0f);

	if (bsp(a, b, c, p))
		std::cout << "Point p is in triangle" << std::endl;
	else
		std::cout << "Point p is not in triangle" << std::endl;

	if (bsp(a, b, c, q))
		std::cout << "Point q is in triangle" << std::endl;
	else
		std::cout << "Point q is not in triangle" << std::endl;

    return (0);
}