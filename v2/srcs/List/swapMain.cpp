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

void	swapMain(std::list<int> *main, std::list<int>::size_type sizeOfPair)
{
	for (int i = sizeOfPair - 1; i + sizeOfPair < main->size(); i += sizeOfPair * 2)
	{
		if (getNbrFromList(*main, i) > getNbrFromList(*main, i + sizeOfPair))
		{
			swap(main, sizeOfPair, i, i + sizeOfPair);
		}
		ListComp++;
	}
}
