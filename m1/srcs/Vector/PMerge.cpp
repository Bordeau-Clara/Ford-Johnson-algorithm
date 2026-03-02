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

std::vector<int>	createPend(std::vector<int> *main, int sizeOfElement)
{
	std::vector<int> pend;
	int i = 0;
	std::vector<int>::size_type maxPair = (main->size() / sizeOfElement); //division is usefull to remove non complete elements

	std::vector<int>::iterator it = main->begin();
	while (it != main->end() && pend.size() < maxPair * sizeOfElement)
	{
		if (std::distance(it, main->end()) < sizeOfElement && i == 0)
			break;
		if (i == sizeOfElement)
		{
			i = 0;
			it += sizeOfElement;
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

void	PMerge(std::vector<int> *main, int sizeOfElement)
{
	std::vector<int> pend;

	swapMain(main, sizeOfElement);
	if (main->size() / (sizeOfElement) >= 2)
		PMerge(main, sizeOfElement * 2);
	pend = createPend(main, sizeOfElement);
	insertPend(main, pend, sizeOfElement);
}
