#ifndef Fixed_HPP
# define Fixed_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <cmath>

class Fixed
{
    private:
        int fixedPointValue;
        static const int fractionalBits = 8;
    
    public:
        Fixed();
        Fixed(const Fixed &Fixed);
        Fixed(const int value);
        Fixed(const float value);
        Fixed &operator = (const Fixed &Fixed);
        ~Fixed();

        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        float   toFloat(void) const;
        int     toInt(void) const;
};

std::ostream &operator <<  (std::ostream &ins, const Fixed &Fixed);

#endif