/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbordeau <bordeau@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 11:08:57 by cbordeau          #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/PMerge.hpp"
#include "../../includes/Vector.hpp"

void	printList(std::vector<int> list, int sizeOfElement)
{
	int i = 0;
	for (std::vector<int>::iterator it = list.begin(); it != list.end(); ++it)
	{
		std::cout << *it;
		if (i % (sizeOfElement) == sizeOfElement - 1)
			std::cout << ", ";
		else
			std::cout << " ";
		i++;
	}
	std::cout << std::endl;
}

void	printInfo(int nbToPlaceId, int pairId, std::vector<int> pend, std::vector<int> main, int decalage)
{
	(void)main;
	(void)pend;
	(void)decalage;
	std::cout << "nbToPlaceId:" << nbToPlaceId << " pairId:" << pairId << std::endl;
	std::cout << "nbToPlace:" << pend[nbToPlaceId] << " pair:" << main[pairId] << std::endl;
}

void	insert(std::vector<int> *vec, std::vector<int> toInsert, int id)
{
	vec->insert(vec->begin() + id, toInsert.begin(), toInsert.end());
}

//idA = index du dernier element de la grande paire
//idB = index du dernier element de la petite paire
//sizeOfElement = nombre de nombre dans la pair - 1
//prend le 1er element de la paire idA comme first
//prend le 1er element de la paire idB comme middle
//prend le dernier element de la paire idB + 1 comme last car last n'est pas pris en compte
//=> insere paire idB avant idA
void	swap(std::vector<int> *vec, int sizeOfElement, int idA, int idB)
{
	std::rotate(vec->begin() + idA - (sizeOfElement - 1), vec->begin() + idB - (sizeOfElement - 1), vec->begin() + idB + 1);
}
