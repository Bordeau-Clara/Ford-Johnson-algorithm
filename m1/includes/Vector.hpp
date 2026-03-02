/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbordeau <bordeau@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 10:37:41 by cbordeau          #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>

extern int VectComp;
//vector PMerge
void		PMerge(std::vector<int> *main, int sizeOfElement);
void		insertPend(std::vector<int> *main, std::vector<int> pend, int sizeOfElement);
void		swapMain(std::vector<int> *main, std::vector<int>::size_type sizeOfElement);
void		swap(std::vector<int> *vec, int sizeOfElement, int idA, int idB);
void		insert(std::vector<int> *vec, std::vector<int> toInsert, int id);
int			holdingToConsider(std::vector<int> holding, int nbToPlaceId, int sizeOfElement);
int			placeNumber(std::vector<int> *main, std::vector<int> pend, int nbToPlaceId, int borne, int sizeOfElement);
void		printList(std::vector<int> list, int sizeOfElement);
void		printInfo(int nbToPlaceId, int pairId, std::vector<int> pend, std::vector<int> main, int decalage);

