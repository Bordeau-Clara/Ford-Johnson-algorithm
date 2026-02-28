/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbordeau <bordeau@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 10:36:30 by cbordeau          #+#    #+#             */
/*   Updated: 2026/02/14 12:09:25 by cbordeau         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
//std::list
#include <list>

extern int ListComp;
//list PMerge
void		PMerge(std::list<int> *main);
void		insertPend(std::list<int> *main, std::list<int> pend, int sizeOfPair);
void		swapMain(std::list<int> *main, std::list<int>::size_type sizeOfPair);
void		swap(std::list<int> *lst, int sizeOfPair, int idA, int idB);
void		insert(std::list<int> *lst, std::list<int> toInsert, int id);
int			holdingToConsider(std::list<int> holding, int nbToPlaceId, int sizeOfPair);
int			placeNumber(std::list<int> *main, std::list<int> pend, int nbToPlaceId, int borne, int sizeOfPair);
void		printList(std::list<int> list, int sizeOfPair);
void		printInfo(int nbToPlaceId, int pairId, std::list<int> pend, std::list<int> main, int decalage);
int			getNbrFromList(std::list<int>& lst, int index);
