/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMerge.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbordeau <bordeau@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 20:00:21 by cbordeau          #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/PMerge.hpp"
#include "../../includes/List.hpp"

std::list<int>	createPend(std::list<int> *main, int sizeOfPair)
{
	std::list<int> pend;
	std::list<int>::iterator it = main->begin();
	bool takeBlock = true;

	while (true)
	{
		std::list<int>::iterator check = it;
		int count = 0;
		while (check != main->end() && count < sizeOfPair)
		{
			++check;
			++count;
		}
		if (count < sizeOfPair)
			break;
		if (takeBlock)
		{
			for (int i = 0; i < sizeOfPair; ++i)
			{
				pend.push_back(*it);
				it = main->erase(it);
			}
		}
		else
		{
			for (int i = 0; i < sizeOfPair; ++i)
				++it;
		}
		takeBlock = !takeBlock;
	}
	return pend;
}

void	PMerge(std::list<int> *main)
{
	int sizeOfPair = 1;
	std::list<int> pend;
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
