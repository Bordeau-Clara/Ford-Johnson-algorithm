/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapMain.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbordeau <bordeau@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 19:59:58 by cbordeau          #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/PMerge.hpp"
#include "../../includes/List.hpp"

void	swapMain(std::list<int> *main, std::list<int>::size_type sizeOfElement)
{
	for (int i = sizeOfElement - 1; i + sizeOfElement < main->size(); i += sizeOfElement * 2)
	{
		if (getNbrFromList(*main, i) > getNbrFromList(*main, i + sizeOfElement))
		{
			swap(main, sizeOfElement, i, i + sizeOfElement);
		}
		ListComp++;
	}
}
