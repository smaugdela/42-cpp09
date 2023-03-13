/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:18:38 by smagdela          #+#    #+#             */
/*   Updated: 2023/03/13 17:28:13 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static void	merge_vect(std::vector<int> &vect, size_t start, size_t half, size_t end)
{

	// https://iq.opengenus.org/merge-insertion-sort/

}

static void	insertion_vect(std::vector<int> &vect, size_t start, size_t end)
{
	if (end == start + 1)
	{
		if (vect[start] > vect[end])
		{
			int	tmp = vect[start];
			vect[start] = vect[end];
			vect[end] = tmp;
		}
	}
}

static void	merge_dq(std::deque<int> &dq, size_t start, size_t half, size_t end)
{}

static void	insertion_dq(std::deque<int> &dq, size_t start, size_t end)
{
	if (end == start + 1)
	{
		if (dq[start] > dq[end])
		{
			int	tmp = dq[start];
			dq[start] = dq[end];
			dq[end] = tmp;
		}
	}
}

static void	vect_sort(std::vector<int> &vect, size_t start, size_t end)
{
	if (end - start > 2)
	{
		size_t	half = (start + end) / 2;
		vect_sort(vect, start, start + half);
		vect_sort(vect, start + half + 1, end);
		merge_vect(vect, start, half, end);
	}
	else
		insertion_vect(vect, start, end);
}

static void	dq_sort(std::deque<int> &dq, size_t start, size_t end)
{
	if (end - start > 2)
	{
		size_t	half = (end - start) / 2;
		dq_sort(dq, start, start + half);
		dq_sort(dq, start + half + 1, end);
		merge_dq(dq, start, half, end);
	}
	else
		insertion_dq(dq, start, end);
}

void	merge_insert_sort(std::deque<int> arg_array)
{
	std::vector<int>	vect;
	vect.insert(vect.begin(), arg_array.begin(), arg_array.end());
	std::deque<int>		dq(arg_array);

	// Time these functions calls to output them later.
	vect_sort(vect, 0, vect.size());
	dq_sort(dq, 0, dq.size());

	// Output the duration of each as well as the resulting ordered array.
	// Plan a specific error if the two resulting containers are not identical, or if one is not ordered.

}
