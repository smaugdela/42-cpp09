/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:18:49 by smagdela          #+#    #+#             */
/*   Updated: 2023/03/14 16:44:00 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP
# define PMERGE_ME_HPP

#include <stdlib.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <iomanip>
#include <vector>
#include <deque>

#define TOKENS "0123456789 +"
#define STR_INT_MAX std::string("2147483647")

int	merge_insert_sort(std::deque<int> arg_array);

#endif // !PMERGE_ME_HPP
