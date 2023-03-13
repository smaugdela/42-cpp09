/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:58:28 by smagdela          #+#    #+#             */
/*   Updated: 2023/03/13 15:39:29 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	solver(std::string arg)
{
	std::stack<int>	stack;

	for(std::string::iterator it = arg.begin(); it !=arg.end(); ++it)
	{
		if (isdigit(*it))
			stack.push(*it - 48);
		else if (*it == ' ')
			continue;
		else if (stack.size() >= 2)
		{
			int x;
			switch (*it)
			{
				case '+':
					x = stack.top();
					stack.pop();
					stack.top() = x + stack.top();
					break;
				case '-':
					x = stack.top();
					stack.pop();
					stack.top() = stack.top() - x;
					break;
				case '*':
					x = stack.top();
					stack.pop();
					stack.top() = x * stack.top();
					break;
				case '/':
					x = stack.top();
					stack.pop();
					stack.top() = stack.top() / x;
					break;
				
				default:
					std::cout << "Error" << std::endl;
					return EXIT_FAILURE;
			}
		}
		else
		{
			std::cout << "Error" << std::endl;
			return EXIT_FAILURE;
		}
	}
	if (stack.size() == 1)
	{
		std::cout << stack.top() << std::endl;
		return EXIT_SUCCESS;
	}
	std::cout << "Error" << std::endl;
	return EXIT_FAILURE;
}
