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
void		PMerge(std::vector<int> *main, std::vector<int> *pend);
void		insertPend(std::vector<int> *main, std::vector<int> newPend, std::vector<int> *pend, std::vector<int> pendOfPend);
void		swapMain(std::vector<int> *main, std::vector<int> *pend);
void		swap(std::vector<int> *vec, int idA, int idB);
void		insert(std::vector<int> *vec, std::vector<int> toInsert, int id);
int			holdingToConsider(std::vector<int> holding, int nbToPlaceId);
int			placeNumber(std::vector<int> *main, std::vector<int> pend, int nbToPlaceId, int borne);
void		printList(std::vector<int> list);
void		printInfo(int nbToPlaceId, int pairId, std::vector<int> pend, std::vector<int> main, int decalage);

