/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbordeau <bordeau@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 13:50:26 by cbordeau          #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PMerge.hpp"
#include "../includes/Vector.hpp"
#include "../includes/List.hpp"

#include <ctime>

double currentTimeMillis()
{
    return static_cast<double>(clock()) * 1000.0 / CLOCKS_PER_SEC;
}

//From emuminov FordJohnson Alogirthm: Humain Explenation & Visualisation
#include <cmath>
#include <cstdlib>

int F(int n)
{
    int sum = 0;
    for (int k = 1; k <= n; ++k) {
        double value = (3.0 / 4.0) * k;
        sum += static_cast<int>(ceil(log2(value)));
    }
    return sum;
}
