/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:18:07 by smagdela          #+#    #+#             */
/*   Updated: 2023/03/13 17:25:31 by smagdela         ###   ########.fr       */
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

	// Check the validity of each arguments and add them to the deque "arg_array" here.

	merge_insert_sort(arg_array);

	return EXIT_SUCCESS;
}
