/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertPendUtils.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbordeau <bordeau@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 20:00:06 by cbordeau          #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/PMerge.hpp"
#include "../../includes/List.hpp"

int	holdingToConsider(std::list<int> holding, int nbToPlaceId, int sizeOfPair)
{
	int toAdd = 0;

	for (std::list<int>::iterator it = holding.begin(); it != holding.end(); ++it)
	{
		if (*it <= nbToPlaceId)
		{
			toAdd += 1;
			nbToPlaceId += sizeOfPair;
		}
	}
	return toAdd;
}

int	placeNumber(std::list<int> *main, std::list<int> pend, int nbToPlaceId, int borne, int sizeOfPair)
{
	std::list<int> toInsert;
	int	toCompare = getNbrFromList(pend, nbToPlaceId);

	for (int i = nbToPlaceId - sizeOfPair + 1; i <= nbToPlaceId; i++)
		toInsert.push_back(getNbrFromList(pend, i));
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
		ListComp++;
		if (toCompare < getNbrFromList(*main, (temp * sizeOfPair) - 1))
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
