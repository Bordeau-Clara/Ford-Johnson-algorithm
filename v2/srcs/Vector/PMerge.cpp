/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMerge.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbordeau <bordeau@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 18:11:48 by cbordeau          #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/PMerge.hpp"
#include "../../includes/Vector.hpp"

std::vector<int>	createPend(std::vector<int> *main, int sizeOfPair)
{
	std::vector<int> pend;
	int i = 0;
	std::vector<int>::size_type maxPair = (main->size() / sizeOfPair) /* / 2 */;

	std::vector<int>::iterator it = main->begin();
	while (it != main->end() && pend.size() < maxPair * sizeOfPair)
	{
		if (std::distance(it, main->end()) < sizeOfPair && i == 0)
			break;
		if (i == sizeOfPair)
		{
			i = 0;
			it += sizeOfPair;
		}
		else
		{
			pend.push_back(*it);
			it = main->erase(it);
			i += 1;
		}
	}
	return pend;
}

void	PMerge(std::vector<int> *main)
{
	int sizeOfPair = 1;
	std::vector<int> pend;
	while (main->size() / (sizeOfPair) >= 2)
	{
		swapMain(main, sizeOfPair);
		sizeOfPair *= 2;
	}
	sizeOfPair /= 2;
	while (sizeOfPair != 0)
	{
		pend.clear();
		pend = createPend(main, sizeOfPair);
		insertPend(main, pend, sizeOfPair);
		sizeOfPair /= 2;
	}
}
