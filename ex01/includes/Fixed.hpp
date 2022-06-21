/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <fmeira@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 14:08:20 by ysoroko           #+#    #+#             */
/*   Updated: 2022/04/28 13:55:37 by fmeira           ###   ########.fr       */
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
		Fixed&	operator=( Fixed const & rhs);
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat(void) const;
		int		toInt(void) const;

	private:
		int				fixed_point_value;
		static const	int n_fract_bits = 8;
};

std::ostream & operator<<( std::ostream & o, Fixed const & rhs);

#endif
