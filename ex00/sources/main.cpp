/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:48:12 by smagdela          #+#    #+#             */
/*   Updated: 2023/03/14 18:02:22 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return (EXIT_FAILURE);
	}

	std::ifstream	file(av[1]);
	if (!file.is_open())
	{
		std::cout << "Error: could not open file." << std::endl;
		return (EXIT_FAILURE);
	}

	std::ifstream	database("data.csv");
	if (!database.is_open())
	{
		std::cout << "Error: could not open csv data." << std::endl;
		return (EXIT_FAILURE);
	}

	return	BitcoinExchange(file, database);
}
