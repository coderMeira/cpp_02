//***************************//
//*Template by pulgamecanica*//
//***************************//

#include "Fixed.hpp"

Fixed::Fixed() : _raw(0){
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed& param) {
	std::cout << "Copy constructor called\n";
	*this = param;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
	// TODO (destructor)
}

Fixed& Fixed::operator= (const Fixed& param) {
	std::cout << "Copy assignement operator called" << std::endl;
	_raw = param.getRawBits();
	return (*this);
}

std::ostream& operator<<(std::ostream& s, const Fixed& param) {
	// s << param.CONST_METHOD()
	(void)param;
	return (s);
}

int		Fixed::getRawBits( void ) const{
	std::cout << "getRawBits member function called" << std::endl;
	return (_raw);
}

void	Fixed::setRawBits(int const raw){
	std::cout << "setRawBits member function called" << std::endl;
	this->_raw = raw;
}

