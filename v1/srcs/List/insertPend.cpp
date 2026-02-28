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

void	insertPend(std::list<int> *main, std::list<int> pend, int sizeOfPair)
{
	int prevJacob = 0;
	int decalage = 0;
	std::list<int> holding;
	int prevId = 0;
	int nbToPlaceId;
	int pairId = 0;

	std::list<int> jacobList = createJacobList<std::list<int> >(pend.size() / sizeOfPair);//pend.size !!!!! Now main cause pend contains rest

	for (std::list<int>::iterator jacob = jacobList.begin(); jacob != jacobList.end(); ++jacob)
	{
		nbToPlaceId = *jacob * sizeOfPair - 1;
		if (prevJacob > *jacob)
		{
			holding.push_back(prevId);
			pairId = nbToPlaceId + decalage;
			pairId += sizeOfPair * holdingToConsider(holding, pairId, sizeOfPair);
			prevId = placeNumber(main, pend, nbToPlaceId, pairId, sizeOfPair);
		}
		else if (prevJacob < *jacob)
		{
			if (*jacob != 1)
				decalage += sizeOfPair;
			decalage += holding.size() * sizeOfPair;
			holding.clear();

			pairId = nbToPlaceId + decalage;
			prevId = placeNumber(main, pend, nbToPlaceId, pairId, sizeOfPair);
		}
		prevJacob = *jacob;
	}
}
