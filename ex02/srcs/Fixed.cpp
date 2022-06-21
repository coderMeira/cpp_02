/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <fmeira@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 14:08:17 by ysoroko           #+#    #+#             */
/*   Updated: 2022/04/23 15:07:11 by fmeira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

int Fixed::getRawBits( void ) const
{
	return (this->fixed_point_value);
}

void	Fixed::setRawBits( int const raw )
{
	this->fixed_point_value = raw;
}

Fixed::Fixed()
{
	this->fixed_point_value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const & src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed & Fixed::operator=( Fixed const & rhs)
{
	std::cout << "Assignation operator called" << std::endl;
	setRawBits(rhs.getRawBits());
	return (*this);
}

Fixed::Fixed(int int_arg)
{
	std::cout << "Int constructor called" << std::endl;
	setRawBits(int_arg << this->n_fract_bits);
}

Fixed::Fixed(float float_arg)
{
	std::cout << "Float constructor called" << std::endl;
	this->setRawBits((int)roundf(float_arg * (1 << this->n_fract_bits)));
}

float Fixed::toFloat(void) const
{
	float	f;

	f = (float)this->getRawBits() / (1 << this->n_fract_bits);
	return (f);
}

int Fixed::toInt(void) const
{
	return (this->getRawBits() >> this->n_fract_bits);
}

std::ostream & operator<<( std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return (o);
}

int Fixed::operator>( Fixed const & rhs) const
{
	if (this->getRawBits() > rhs.getRawBits())
		return (1);
	return (0);
}

int Fixed::operator<( Fixed const & rhs) const
{
	if (this->getRawBits() < rhs.getRawBits())
		return (1);
	return (0);
}

int Fixed::operator>=( Fixed const & rhs) const
{
	if (this->getRawBits() >= rhs.getRawBits())
		return (1);
	return (0);
}

int Fixed::operator<=( Fixed const & rhs) const
{
	if (this->getRawBits() <= rhs.getRawBits())
		return (1);
	return (0);
}

int Fixed::operator==( Fixed const & rhs) const
{
	if (this->getRawBits() == rhs.getRawBits())
		return (1);
	return (0);
}

int Fixed::operator!=( Fixed const & rhs) const
{
	if (this->getRawBits() != rhs.getRawBits())
		return (1);
	return (0);
}

Fixed Fixed::operator+( Fixed const & rhs) const
{
	Fixed ret(this->toFloat() + rhs.toFloat());

	return (ret);
}

Fixed Fixed::operator-( Fixed const & rhs) const
{
	Fixed ret(this->toFloat() - rhs.toFloat());

	return (ret);
}

Fixed Fixed::operator*( Fixed const & rhs) const
{
	Fixed ret(this->toFloat() * rhs.toFloat());

	return (ret);
}

Fixed Fixed::operator/( Fixed const & rhs) const
{
	Fixed ret(this->toFloat() / rhs.toFloat());

	return (ret);
}

Fixed & Fixed::operator++( void )
{
	this->fixed_point_value += 1;
	return (*this);
}

Fixed & Fixed::operator--( void )
{
	this->fixed_point_value -= 1;
	return (*this);
}

Fixed Fixed::operator++( int )
{
	Fixed	temp = *this;

	(this->fixed_point_value) +=1 ;
	return (temp);
}

Fixed Fixed::operator--( int )
{
	Fixed	temp = *this;

	(this->fixed_point_value) -=1 ;
	return (temp);
}

const Fixed & Fixed::min(const Fixed & a, const Fixed & b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed & Fixed::max(const Fixed & a, const Fixed & b)
{
	if (a > b)
		return (a);
	return (b);
}

Fixed & Fixed::min(Fixed & a, Fixed & b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed & Fixed::max(Fixed & a, Fixed & b)
{
	if (a > b)
		return (a);
	return (b);
}
