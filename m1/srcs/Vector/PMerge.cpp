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

std::vector<int>	createPend(std::vector<int> *main, std::vector<int> *pend, std::vector<int> * pendOfPend)
{
	std::vector<int> newPend;
	int i = 0;
	std::vector<int>::size_type maxPair = main->size();

	std::vector<int>::iterator it = main->begin();
	while (it != main->end() && newPend.size() < maxPair)
	{
		if (std::distance(it, main->end()) < 1 && i == 0)
			break;
		if (i == 1)
		{
			i = 0;
			it += 1;
		}
		else
		{
			newPend.push_back(*it);
			it = main->erase(it);
			i += 1;
		}
	}
	return newPend;
}

void	PMerge(std::vector<int> *main, std::vector<int> *pend)
{
	std::vector<int> newPend;
	std::vector<int> pendOfPend;
	swapMain(main, pend);
	newPend = createPend(main, pend, &pendOfPend);
	if (main->size() >= 2)
		PMerge(main, &newPend);
	insertPend(main, newPend, pend, pendOfPend);
}
