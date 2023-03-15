/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:48:57 by smagdela          #+#    #+#             */
/*   Updated: 2023/03/15 17:56:23 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "Date.hpp"

int	BitcoinExchange(std::ifstream &file, std::ifstream &database_file)
{
	std::map<Date, float>	db;
	std::string				line;
	std::string				date;
	Date					key;
	std::string				value;

	// Load csv database into map container.
	while (getline(database_file, line))
	{
		if (line.empty())
			continue ;

		date = line.substr(0, line.find(','));
		key = Date(date);

		if (key.is_valid() == false)
			continue ;

		value = line.substr(line.find(',') + 1);
		if (value.find_first_not_of("0123456789.", 0) != std::string::npos)
			continue ;

		db[key] = std::atof(value.c_str());
	}

	size_t	len;
	// Read file line by line and print the value of the bitcoin at the date of the transaction.
	while (getline(file, line))
	{
		if (line.empty())
			continue ;

		date = line.substr(0, line.find(' '));
		key	= Date(date);

		value = line.substr(line.find('|') + 1);
		len = value.find_first_not_of(" \n\t\v\f\r");
		value.erase(0, len);
		len = value.find_last_not_of(" \n\t\v\f\r");
		value.erase(len + 1);

		if (key.is_valid() == false)
			std::cout << "Error: bad input => " << key.getRaw() << std::endl;
		else if (value.find_first_not_of("0123456789-.,", 0) != std::string::npos)
			std::cout << "Error: bad value input => " << value << std::endl;
		else if (value.size() > 10 || (value.size() == 10 && value.compare(STR_INT_MAX) > 0))
			std::cout << "Error: too large a number." << std::endl;
		else if (std::atof(value.c_str()) < 0.0)
			std::cout << "Error: not a positive number." << std::endl;
		else
		{
			std::map<Date, float>::iterator	it;
			it = db.lower_bound(key);
			if (it == db.begin() && it->first != key)
				std::cout << "Error: no data that early." << std::endl;
			else if (it == db.end())
				std::cout << "Error: no data that late." << std::endl;
			else
			{
				if (it->first != key)
					--it;
				std::cout << key.getRaw() << " => " << value << " = " << std::atof(value.c_str()) * it->second << std::endl;
			}
		}
	}
	return EXIT_SUCCESS;
}
