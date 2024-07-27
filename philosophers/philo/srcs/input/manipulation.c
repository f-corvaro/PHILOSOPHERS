/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:48:01 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/06/17 14:52:13 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Converts a string to a positive integer.
 *
 * This function takes a string of digits and converts it to its corresponding
 * positive integer value. If the string represents a number greater than 
 * INT_MAX, the function returns -1.
 *
 * @param str The string to convert.
 * @return The integer representation of the string, or -1 if the string 
 * represents a number greater than INT_MAX.
 */
int	pos_atoi(char *str)
{
	int						i;
	unsigned long long int	nb;

	i = 0;
	nb = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	if (nb > INT_MAX)
		return (-1);
	return ((int)nb);
}
