/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertPendUtils.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbordeau <bordeau@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 19:47:40 by cbordeau          #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/PMerge.hpp"
#include "../../includes/Vector.hpp"


int	holdingToConsider(std::vector<int> holding, int nbToPlaceId, int sizeOfPair)
{
	int toAdd = 0;

	for (std::vector<int>::iterator it = holding.begin(); it != holding.end(); ++it)
	{
		if (*it <= nbToPlaceId)
		{
			toAdd += 1;
			nbToPlaceId += sizeOfPair;
		}
	}
	return toAdd;
}

int	placeNumber(std::vector<int> *main, std::vector<int> pend, int nbToPlaceId, int borne, int sizeOfPair)
{
	std::vector<int> toInsert;
	int	toCompare = pend[nbToPlaceId];

	for (int j = nbToPlaceId - sizeOfPair + 1; j <= nbToPlaceId; j++)
		toInsert.push_back(pend[j]);
	int i = 0;
	if (borne == sizeOfPair - 1)
	{
		i = 0;
		insert(main, toInsert, i);
		return i;
	}
	int temp, downBorne = 0, upBorne = (borne + 1) / sizeOfPair;
	while(upBorne - downBorne != 1 && upBorne != downBorne)
	{
		temp = downBorne + ((upBorne - downBorne) / 2);
		VectComp++;
		if (toCompare < (*main)[(temp * sizeOfPair) - 1])
		{
			upBorne = temp;
		}
		else
		{
			downBorne = temp;
		}
	}
	i += downBorne * sizeOfPair;
	insert(main, toInsert, i);
	return i;
}
