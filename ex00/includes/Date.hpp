/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:33:17 by smagdela          #+#    #+#             */
/*   Updated: 2023/03/15 16:11:13 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATE_HPP
# define DATE_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <limits.h>

class Date
{

	public:

		Date( void );
		Date( std::string str_date );
		Date( Date const & src );
		~Date();

		Date &		operator=( Date const & rhs );
		bool		operator<( Date const & rhs ) const;
		bool		operator>( Date const & rhs ) const;
		bool		operator==( Date const & rhs ) const;
		bool		operator<=( Date const & rhs ) const;
		bool		operator>=( Date const & rhs ) const;

		bool		is_valid( void ) const;

		std::string	getRaw( void ) const;

	private:


		std::string	_raw;
		int			_year;
		int			_month;
		int			_day;
		bool		_validity;

};

#endif /* ************************************************************ DATE_H */
