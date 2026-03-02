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

void	swapMain(std::vector<int> *main, std::vector<int>::size_type sizeOfElement)
{
	for (int i = sizeOfElement - 1; i + sizeOfElement < main->size(); i += sizeOfElement * 2)
	{
		if ((*main)[i] > (*main)[i + sizeOfElement])
		{
			swap(main, sizeOfElement, i, i + sizeOfElement);
		}
		VectComp++;
	}
}
