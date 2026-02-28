/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMerge.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbordeau <bordeau@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 18:28:17 by cbordeau          #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>
// #include <cstdlib>
// #include <utility>
// #include <vector>


double currentTimeMillis();
int F(int n);

template <typename Container>
int	pushToVec(char* nb, Container *main)
{
	long nbr = strtol(nb, NULL, 10);
	if (nbr < 0)
		return 0;
	if (nbr > 2147483647)
		return 0;
	main->push_back(nbr);
	return 1;
}

template <typename Container>
int isSorted(Container* main)
{
    if (main->size() < 2)
        return 1;

    typename Container::iterator it = main->begin();
    typename Container::iterator next = it;
    ++next;

    for (; next != main->end(); ++it, ++next)
    {
        if (*it > *next)
		{
		 std::cerr << *it << " is greater than " << *next << std::endl;
            return 0;
		}
    }
    return 1;
}

template <typename Container>
Container createJacobList(typename Container::size_type length)
{
	int current = 3;
	int prev = 1;
	int temp;
	Container jacobList;

	if (length == 0)
	   return jacobList;
	jacobList.push_back(1);
	while (jacobList.size() != length)
	{
		if (current > static_cast<int>(length))
			current = length;
		for (int i = current; i != prev; i--)
			jacobList.push_back(i);
		temp = current;
		current = current + 2 * prev;
		prev = temp;
	}
	return jacobList;
}
