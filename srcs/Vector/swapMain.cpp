/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapMain.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbordeau <bordeau@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 14:32:28 by cbordeau          #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/PMerge.hpp"
#include "../../includes/Vector.hpp"

void	swapMain(std::vector<int> *main, std::vector<int>::size_type sizeOfPair)
{
	for (int i = sizeOfPair - 1; i + sizeOfPair < main->size(); i += sizeOfPair * 2)
	{
		if ((*main)[i] > (*main)[i + sizeOfPair])
		{
			swap(main, sizeOfPair, i, i + sizeOfPair);
		}
		VectComp++;
	}
}
