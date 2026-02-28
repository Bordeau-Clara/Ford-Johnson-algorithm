/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertPend.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbordeau <bordeau@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 16:01:16 by cbordeau          #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/PMerge.hpp"
#include "../../includes/Vector.hpp"

void	insertPend(std::vector<int> *main, std::vector<int> pend, int sizeOfElement)
{
	int prevJacob = 0;
	int decalage = 0;
	std::vector<int> holding;
	int prevId = 0;
	int nbToPlaceId;
	int pairId = 0;

	std::vector<int> jacobList = createJacobList<std::vector<int> >(pend.size() / sizeOfElement);//pend.size !!!!! Now main cause pend contains rest

	for (std::vector<int>::iterator jacob = jacobList.begin(); jacob != jacobList.end(); ++jacob)
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
