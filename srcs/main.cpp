/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbordeau <cbordeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:54:14 by cbordeau          #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PMerge.hpp"
#include "../includes/Vector.hpp"
#include "../includes/List.hpp"

// ./PMerge $(shuf -i 1-1000 -n 20)

int VectComp = 0;
int ListComp = 0;

int main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cerr << "Wrong number of arguments" << std::endl;
		std::cerr << "Please enter a list of positive integer" << std::endl;
		return 1;
	}
	int size = ac - 1;
	int maxComp = F(size);
	//print list
	std::cout << "Start list is:" << std::endl;
	for (int i = 1; i < ac; i++)
	{
		std::cout << av[i];
	  std::cout << ", ";
	}
	std::cout << std::endl;
	{
		double start = currentTimeMillis();
		std::vector<int> main;
		for (int i = 1; i < ac; i++)
		{
			//have to check for double nbr and char in numbers
			if (!pushToVec(av[i], &main))
				std::cerr << "Please enter a positive integer" << std::endl;//print error
		}
		PMerge(&main);
		double end = currentTimeMillis();
		//check sorted vector
		if (!isSorted(&main))
		{
			std::cerr << "[vect is not ordered]" << std::endl;
			return 1;
		}
		std::cout << "Sorted list is:" << std::endl;
		printList(main, 1);
		std::cout << "Time to process a range of " << size << " elements with std::vector:"<< (end - start) << " ms" << std::endl;

	}
	{
		double start = currentTimeMillis();
		std::list<int> main;
		for (int i = 1; i < ac; i++)
		{
			//have to check for double nbr and char in numbers
			if (!pushToVec(av[i], &main))
				std::cerr << "Please enter a positive integer" << std::endl;//print error
		}
		PMerge(&main);
		double end = currentTimeMillis();
		//check sorted list
		if (!isSorted(&main))
		{
			std::cerr << "[list is not ordered]" << std::endl;
			return 1;
		}
		std::cout << "Time to process a range of " << size << " elements with std::list:"<< (end - start) << " ms" << std::endl;
	}
	std::cout << "maxComp:" << maxComp << std::endl;
	std::cout << "vect comp:" << VectComp << std::endl;
	std::cout << "list comp:" << ListComp << std::endl;

	if (VectComp > maxComp)
	{
		std::cerr << "[Too many comparisions]" << std::endl;
		std::cerr << "VectComp [" << VectComp << "] is greater than maxComp [" << maxComp << "]" << std::endl;
		return 1;
	}
	if (ListComp > maxComp)
	{
		std::cerr << "[Too many comparisions]" << std::endl;
		std::cerr << "ListComp [" << ListComp << "] is greater than maxComp [" << maxComp << "]" << std::endl;
		return 1;
	}
	return 0;
}
