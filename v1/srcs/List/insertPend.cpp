/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertPend.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbordeau <bordeau@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 20:00:13 by cbordeau          #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/PMerge.hpp"
#include "../../includes/List.hpp"

void	insertPend(std::list<int> *main, std::list<int> pend, int sizeOfElement)
{
	int prevJacob = 0;
	int decalage = 0;
	std::list<int> holding;
	int prevId = 0;
	int nbToPlaceId;
	int pairId = 0;

	std::list<int> jacobList = createJacobList<std::list<int> >(pend.size() / sizeOfElement);//pend.size !!!!! Now main cause pend contains rest

	for (std::list<int>::iterator jacob = jacobList.begin(); jacob != jacobList.end(); ++jacob)
	{
		nbToPlaceId = *jacob * sizeOfElement - 1;
		if (prevJacob > *jacob)
		{
			holding.push_back(prevId);
			pairId = nbToPlaceId + decalage;
			pairId += sizeOfElement * holdingToConsider(holding, pairId, sizeOfElement);
			prevId = placeNumber(main, pend, nbToPlaceId, pairId, sizeOfElement);
		}
		else if (prevJacob < *jacob)
		{
			if (*jacob != 1)
				decalage += sizeOfElement;
			decalage += holding.size() * sizeOfElement;
			holding.clear();

			pairId = nbToPlaceId + decalage;
			prevId = placeNumber(main, pend, nbToPlaceId, pairId, sizeOfElement);
		}
		prevJacob = *jacob;
	}
}
