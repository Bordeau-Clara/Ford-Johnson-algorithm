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

void	insertPend(std::vector<int> *main, std::vector<int> pend)
{
	int prevJacob = 0;
	int decalage = 0;
	std::vector<int> holding;
	int prevId = 0;
	int nbToPlaceId;
	int pairId = 0;

	std::vector<int> jacobList = createJacobList<std::vector<int> >(pend.size());

	for (std::vector<int>::iterator jacob = jacobList.begin(); jacob != jacobList.end(); ++jacob)
	{
		nbToPlaceId = *jacob - 1;
		if (prevJacob > *jacob)
		{
			holding.push_back(prevId);
			pairId = nbToPlaceId + decalage;
			pairId += holdingToConsider(holding, pairId);
			prevId = placeNumber(main, pend, nbToPlaceId, pairId);
		}
		else if (prevJacob < *jacob)
		{
			if (*jacob != 1)
				decalage += 1;
			decalage += holding.size();
			holding.clear();

			pairId = nbToPlaceId + decalage;
			prevId = placeNumber(main, pend, nbToPlaceId, pairId);
		}
		prevJacob = *jacob;
	}
}
