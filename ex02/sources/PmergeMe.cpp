/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:18:38 by smagdela          #+#    #+#             */
/*   Updated: 2023/03/14 16:31:30 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static void	merge_vect(std::vector<int> &vect, size_t start, size_t half, size_t end)
{
	std::vector<int>	left_array(vect.begin() + start, vect.begin() + half + 1);
	std::vector<int>	right_array(vect.begin() + half + 1, vect.begin() + end + 1);

	size_t	left_index = 0;
	size_t	right_index = 0;

	for(size_t i = start; i < end + 1; ++i)
	{
		if (left_index == left_array.size())
		{
			vect[i] = right_array[right_index];
			++right_index;
		}
		else if (right_index == right_array.size())
		{
			vect[i] = left_array[left_index];
			++left_index;
		}
		else if (left_array[left_index] < right_array[right_index])
		{
			vect[i] = left_array[left_index];
			++left_index;
		}
		else
		{
			vect[i] = right_array[right_index];
			++right_index;
		}
	}
}

static void	insertion_vect(std::vector<int> &vect, size_t start, size_t end)
{
	if (vect[start] > vect[end])
	{
		int	tmp = vect[start];
		vect[start] = vect[end];
		vect[end] = tmp;
	}
}

static void	merge_dq(std::deque<int> &dq, size_t start, size_t half, size_t end)
{
	std::deque<int>	left_array(dq.begin() + start, dq.begin() + half + 1);
	std::deque<int>	right_array(dq.begin() + half + 1, dq.begin() + end + 1);

	size_t	left_index = 0;
	size_t	right_index = 0;

	for(size_t i = start; i < end + 1; ++i)
	{
		if (left_index == left_array.size())
		{
			dq[i] = right_array[right_index];
			++right_index;
		}
		else if (right_index == right_array.size())
		{
			dq[i] = left_array[left_index];
			++left_index;
		}
		else if (left_array[left_index] < right_array[right_index])
		{
			dq[i] = left_array[left_index];
			++left_index;
		}
		else
		{
			dq[i] = right_array[right_index];
			++right_index;
		}
	}
}

static void	insertion_dq(std::deque<int> &dq, size_t start, size_t end)
{
	if (dq[start] > dq[end])
	{
		int	tmp = dq[start];
		dq[start] = dq[end];
		dq[end] = tmp;
	}
}

static void	vect_sort(std::vector<int> &vect, size_t start, size_t end)
{
	if (end - start >= 2)
	{
		size_t	half = (start + end) / 2;
		vect_sort(vect, start, half);
		vect_sort(vect, half + 1, end);
		merge_vect(vect, start, half, end);
	}
	else
		insertion_vect(vect, start, end);
}

static void	dq_sort(std::deque<int> &dq, size_t start, size_t end)
{
	if (end - start >= 2)
	{
		size_t	half = (start + end) / 2;
		dq_sort(dq, start, half);
		dq_sort(dq, half + 1, end);
		merge_dq(dq, start, half, end);
	}
	else
		insertion_dq(dq, start, end);
}

int	merge_insert_sort(std::deque<int> arg_array)
{
	std::vector<int>	vect;
	vect.insert(vect.begin(), arg_array.begin(), arg_array.end());
	std::deque<int>		dq(arg_array);

	clock_t	vect_time, dq_time;

	vect_time = clock();
	vect_sort(vect, 0, vect.size() - 1);
	vect_time = clock() - vect_time;

	dq_time = clock();
	dq_sort(dq, 0, dq.size() - 1);
	dq_time = clock() - dq_time;

	if (vect.size() != dq.size())
	{
		std::cout << "Error: vect and dq are not the same size." << std::endl;
		return EXIT_FAILURE;
	}
	for (size_t i = 0; i < vect.size(); ++i)
	{
		if (vect[i] != dq[i])
		{
			std::cout << "Error: vect and dq are not identical." << std::endl;
			return EXIT_FAILURE;
		}
	}

	for (size_t i = 0; i < vect.size() - 1; ++i)
	{
		if (vect[i] > vect[i + 1])
		{
			std::cout << "Error: vect is not sorted." << std::endl;
			return EXIT_FAILURE;
		}
	}
	for (size_t i = 0; i < dq.size() - 1; ++i)
	{
		if (dq[i] > dq[i + 1])
		{
			std::cout << "Error: dq is not sorted." << std::endl;
			return EXIT_FAILURE;
		}
	}

	std::cout << "Before:";
	for (size_t i = 0; i < arg_array.size() && i < 4; ++i)
		std::cout << " " << arg_array[i];
	if (arg_array.size() == 5)
		std::cout << " " << arg_array[4];
	else if (arg_array.size() > 5)
		std::cout << " [...]";
	std::cout << std::endl;

	std::cout << "After: ";
	for (size_t i = 0; i < dq.size() && i < 4; ++i)
		std::cout << " " << dq[i];
	if (dq.size() == 5)
		std::cout << " " << dq[4];
	else if (dq.size() > 5)
		std::cout << " [...]";
	std::cout << std::endl;

	double time = (double)vect_time / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << arg_array.size() << " elements with std::vector : " << std::fixed << std::setprecision(6) << time << " s" << std::endl;
	time = (double)dq_time / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << arg_array.size() << " elements with std::deque  : " << std::fixed << std::setprecision(6) << time << " s" << std::endl;

	return EXIT_SUCCESS;
}
