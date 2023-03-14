/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:48:57 by smagdela          #+#    #+#             */
/*   Updated: 2023/03/14 18:28:40 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	BitcoinExchange(std::ifstream &file, std::ifstream &database_file)
{
	std::map<std::string, float>	db;
	std::string						line;
	std::string						date;
	std::string						value;

	// Load csv database into map container.
	while (getline(database_file, line))
	{
		if (line.empty())
			continue ;
		date = line.substr(0, line.find(','));
		if (date.size() != 10 || date[4] != '-' || date[7] != '-' || date.find_first_not_of("0123456789-", 0) != std::string::npos)
		{
			std::cout << "Error: invalid csv date format." << std::endl;
			return (EXIT_FAILURE);
		}
		value = line.substr(line.find(',') + 1);
		if (value.find_first_not_of("0123456789.", 0) != std::string::npos)
		{
			std::cout << "Error: invalid csv value format." << std::endl;
			return (EXIT_FAILURE);
		}
		db[date] = std::atof(value.c_str());
	}

	// Read file line by line and print the value of the bitcoin at the date of the transaction.
	while (getline(file, line))
	{
		if (line.empty())
			continue ;

		// Should create a Date class to help manipulate dates.

	}
}
