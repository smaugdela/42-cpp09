/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:53:41 by smagdela          #+#    #+#             */
/*   Updated: 2023/03/13 15:39:19 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int ac, char** av)
{
	if (ac == 2)
		return solver(std::string(av[1]));
	std::cout << "Error" << std::endl;
	return EXIT_FAILURE;
}
