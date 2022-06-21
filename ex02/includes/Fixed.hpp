/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <fmeira@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 14:08:20 by ysoroko           #+#    #+#             */
/*   Updated: 2022/04/28 14:53:24 by fmeira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed
{
	public:
		Fixed();
		Fixed(Fixed const & src);
		Fixed(int const int_arg);
		Fixed(float const float_arg);
		~Fixed();
		Fixed & operator=( Fixed const & rhs);
		int operator>( Fixed const & rhs) const;
		int operator<( Fixed const & rhs) const;
		int operator>=( Fixed const & rhs) const;
		int operator<=( Fixed const & rhs) const;
		int operator==( Fixed const & rhs) const;
		int operator!=( Fixed const & rhs) const;

		Fixed operator+( Fixed const & rhs) const;
		Fixed operator-( Fixed const & rhs) const;
		Fixed operator*( Fixed const & rhs) const;
		Fixed operator/( Fixed const & rhs) const;

		Fixed & operator++( void );
		Fixed & operator--( void );
		Fixed operator++( int n );
		Fixed operator--( int n );

		static Fixed & min(Fixed & a, Fixed & b );
		static Fixed & max(Fixed & a, Fixed & b );
		static const Fixed & min(const Fixed & a, const Fixed & b );
		static const Fixed & max(const Fixed & a, const Fixed & b );
		int		getRawBits( void ) const;
		void 	setRawBits( int const raw );
		float	toFloat(void) const;
		int		toInt(void) const;

	private:
		int				fixed_point_value;
		static const	int n_fract_bits = 8;
};

std::ostream & operator<<( std::ostream & o, Fixed const & rhs);

#endif
