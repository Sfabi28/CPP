#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed x = point.getX();
    Fixed y = point.getY();

    const Fixed zero(0);
    const Fixed one(1);

    Fixed xa = a.getX();
    Fixed xb = b.getX();
    Fixed xc = c.getX();
    Fixed ya = a.getY();
    Fixed yb = b.getY();
    Fixed yc = c.getY();

    Fixed D1 = (x - xa) * (yc - ya) - (y - ya) * (xc - xa);
    Fixed D2 = (xa - x) * (yb - ya) - (ya - y) * (xb - xa);
    Fixed D = (xb - xa) * (yc - ya) - (yb - ya) * (xc - xa);

    if (D == zero)
        return (false);

    Fixed A = D1 / D;
    Fixed B = D2 / D;
    
    return (A > zero && B > zero && A + B < one);
}