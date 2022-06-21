//***************************//
//*Template by pulgamecanica*//
//***************************//

#ifndef __Fixed_HPP__
# define __Fixed_HPP__

#include <iostream>

class Fixed {
	public:
		Fixed();
		Fixed(const Fixed&);
		~Fixed();
		Fixed&	operator= (const Fixed&); // const for safety... not super nesessary
		int		getRawBits(void) const; //returns the raw value of the fixed-point value.
		void	setRawBits(int const raw); //sets the raw value of the fixed-point number.
	private:
		int					_raw;
		static const int	bits = 8;
};

std::ostream&	operator<<(std::ostream&, const Fixed&);

#endif

