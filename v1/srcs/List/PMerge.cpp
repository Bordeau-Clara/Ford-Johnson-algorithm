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

std::list<int>	createPend(std::list<int> *main, int sizeOfElement)
{
	std::list<int> pend;
	std::list<int>::iterator it = main->begin();
	bool takeBlock = true;

	while (true)
	{
		std::list<int>::iterator check = it;
		int count = 0;
		while (check != main->end() && count < sizeOfElement)
		{
			++check;
			++count;
		}
		if (count < sizeOfElement)
			break;
		if (takeBlock)
		{
			for (int i = 0; i < sizeOfElement; ++i)
			{
				pend.push_back(*it);
				it = main->erase(it);
			}
		}
		else
		{
			for (int i = 0; i < sizeOfElement; ++i)
				++it;
		}
		takeBlock = !takeBlock;
	}
	return pend;
}

void	PMerge(std::list<int> *main)
{
	int sizeOfElement = 1;
	std::list<int> pend;
	while (main->size() / (sizeOfElement) >= 2)
	{
		swapMain(main, sizeOfElement);
		sizeOfElement *= 2;
	}
	sizeOfElement /= 2;
	while (sizeOfElement != 0)
	{
		pend.clear();
		pend = createPend(main, sizeOfElement);
		insertPend(main, pend, sizeOfElement);
		sizeOfElement /= 2;
	}
}
