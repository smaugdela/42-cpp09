/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:18:07 by smagdela          #+#    #+#             */
/*   Updated: 2023/03/14 16:53:27 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << "Error" << std::endl;
		return EXIT_FAILURE;
	}
	std::deque<int>	arg_array;

	for (int i = 1; i < ac; ++i)
	{
		std::string	arg(av[i]);
		if (!arg.size() || arg.find_first_not_of(TOKENS) != std::string::npos || arg.size() > 10 || (arg.size() == 10 && arg.compare(STR_INT_MAX) > 0))
		{
			std::cout << "Error" << std::endl;
			return EXIT_FAILURE;
		}
		arg_array.push_back(std::atoi(arg.c_str()));
	}

	return merge_insert_sort(arg_array);
}
