/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:49:23 by smagdela          #+#    #+#             */
/*   Updated: 2023/03/15 14:30:02 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <map>

#define STR_INT_MAX std::string("2147483647")

int	BitcoinExchange(std::ifstream &file, std::ifstream &database);

#endif
