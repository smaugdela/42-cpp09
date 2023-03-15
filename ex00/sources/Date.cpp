/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:33:17 by smagdela          #+#    #+#             */
/*   Updated: 2023/03/15 16:15:18 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Date.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Date::Date() : _raw(), _year(INT_MAX), _month(INT_MAX), _day(INT_MAX), _validity(false)
{}

Date::Date( std::string str_date )
{
	// Trim spaces from str_date
	size_t	len;

	len = str_date.find_first_not_of(" \n\t\v\f\r");
	str_date.erase(0, len);
	len = str_date.find_last_not_of(" \n\t\v\f\r");
	str_date.erase(len + 1);

	std::string	year, month, day;
	year = str_date.substr(0, 4);
	month = str_date.substr(2, 2);
	day = str_date.substr(2, 2);

	this->_year = std::atoi(year.c_str());
	this->_month = std::atoi(month.c_str());
	this->_day = std::atoi(day.c_str());

	// Check the validity of this date
	if (_raw.size() == 10 && _raw[4] == '-' && _raw[7] == '-' && _raw.find_first_not_of("0123456789-") == std::string::npos
		&& (_month > 0 && _month < 13) && (_day > 0 && _day < 32))
	{
		_validity = true;
	}
	else
		_validity = false;
}

Date::Date( const Date & src ) : _raw(src._raw), _year(src._year), _month(src._month), _day(src._day), _validity(src._validity)
{}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Date::~Date()
{}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Date &				Date::operator=( Date const & rhs )
{
	if ( this != &rhs )
	{
		this->_raw = rhs._raw;
		this->_year = rhs._year;
		this->_month = rhs._month;
		this->_day= rhs._day;
		this->_validity = rhs._validity;
	}
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

bool		Date::operator<( Date const & rhs ) const
{
	if (this->_validity == false || rhs.is_valid() == false)
		return (false);

	if (this->_raw.compare(rhs._raw) < 0)
		return true;
	return false;
}

bool		Date::operator>( Date const & rhs ) const
{
	if (this->_validity == false || rhs.is_valid() == false)
		return (false);
	
	if (this->_raw.compare(rhs._raw) > 0)
		return true;
	return false;
}

bool		Date::operator==( Date const & rhs ) const
{
	if (this->_validity == false || rhs.is_valid() == false)
		return (false);

	if (this->_raw.compare(rhs._raw) == 0)
		return true;
	return false;
}

bool		Date::operator<=( Date const & rhs ) const
{
	if (this->_validity == false || rhs.is_valid() == false)
		return (false);

	if (*this < rhs || *this == rhs)
		return true;
	return false;
}

bool		Date::operator>=( Date const & rhs ) const
{
	if (this->_validity == false || rhs.is_valid() == false)
		return (false);

	if (*this > rhs || *this == rhs)
		return true;
	return false;
}

bool		Date::is_valid( void ) const
{
	return (this->_validity);
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	Date::getRaw( void ) const
{
	return _raw;
}


/* ************************************************************************** */
