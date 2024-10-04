#ifndef Point_HPP
# define Point_HPP

# include "Fixed.hpp"

class   Point
{
    private:
        Fixed x;
        Fixed y;

    public:
        Point();
        Point(float const p1, float const p2);
        Point(const Point &point);
        Point &operator = (const Point &point);
        ~Point();

        Fixed   getX(void) const;
        Fixed   getY(void) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif