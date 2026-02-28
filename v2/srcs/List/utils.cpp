/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbordeau <bordeau@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 18:42:49 by cbordeau          #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/PMerge.hpp"
#include "../../includes/List.hpp"

void	printList(std::list<int> list, int sizeOfElement)
{
	int i = 0;
	for (std::list<int>::iterator it = list.begin(); it != list.end(); ++it)
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

void	printInfo(int nbToPlaceId, int pairId, std::list<int> pend, std::list<int> main, int decalage)
{
	std::cout << "nbToPlaceId:" << nbToPlaceId << " pairId:" << pairId << std::endl;
	std::cout << "nbToPlace:" << getNbrFromList(pend, nbToPlaceId) << " pair:" << getNbrFromList(main, pairId) << std::endl;
	std::cout << "decalage:" << decalage << std::endl;
}

void	insert(std::list<int> *lst, std::list<int> toInsert, int id)
{
	std::list<int>::iterator it = lst->begin();
	std::advance(it, id);
	lst->insert(it, toInsert.begin(), toInsert.end());
}

//idA = index du dernier element de la grande paire
//idB = index du dernier element de la petite paire
//sizeOfElement = nombre de nombre dans la pair - 1
//prend le 1er element de la paire idA comme first
//prend le 1er element de la paire idB comme middle
//prend le dernier element de la paire idB + 1 comme last car last n'est pas pris en compte
//=> insere paire idB avant idA
void	swap(std::list<int> *lst, int sizeOfElement, int idA, int idB)
{
	std::list<int>::iterator first = lst->begin();
	std::advance(first, idA - (sizeOfElement - 1));
	
	std::list<int>::iterator middle = lst->begin();
	std::advance(middle, idB - (sizeOfElement - 1));
	
	std::list<int>::iterator last = lst->begin();
	std::advance(last, idB + 1);

	lst->splice(first, *lst, middle, last);
}

int getNbrFromList(std::list<int>& lst, int index)
{
    std::list<int>::iterator it = lst.begin();
    std::advance(it, index);
    return *it;
}
