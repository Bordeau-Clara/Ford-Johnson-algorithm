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

void	swapMain(std::vector<int> *main)
{
	for (int i = 0; i + 1 < main->size(); i += 2)
	{
		if ((*main)[i] > (*main)[i + 1])
		{
			swap(main, i, i + 1);
		}
		VectComp++;
	}
}
