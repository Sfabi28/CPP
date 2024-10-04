#ifndef Fixed_HPP
# define Fixed_HPP

# include <iostream>
# include <string>
# include <iomanip>

class Fixed
{
    private:
        int fixedPointValue;
        static const int fractionalBits = 8;
    
    public:
        Fixed();
        Fixed(const Fixed &Fixed);
        Fixed &operator = (const Fixed &Fixed);
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif