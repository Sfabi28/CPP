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
        Fixed(const Fixed &fixed);
        Fixed(const int value);
        Fixed(const float value);
        Fixed &operator = (const Fixed &fixed);
        ~Fixed();

        bool    operator > (const Fixed &fixed);
        bool    operator < (const Fixed &fixed);
        bool    operator >= (const Fixed &fixed);
        bool    operator <= (const Fixed &fixed);
        bool    operator == (const Fixed &fixed);
        bool    operator != (const Fixed &fixed);
        Fixed   operator + (const Fixed &fixed);
        Fixed   operator - (const Fixed &fixed);
        Fixed   operator * (const Fixed &fixed);
        Fixed   operator / (const Fixed &fixed);
        Fixed   &operator ++ (void);
        Fixed   &operator -- (void);
        Fixed   operator ++ (int);
        Fixed   operator -- (int);


        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        float   toFloat(void) const;
        int     toInt(void) const;

        static Fixed   min(Fixed &a, Fixed &b);
        static Fixed   min(const Fixed &a, const Fixed &b);
        static Fixed   max(Fixed &a, Fixed &b);
        static Fixed   max(const Fixed &a, const Fixed &b);
};

std::ostream &operator <<  (std::ostream &ins, const Fixed &fixed);

#endif