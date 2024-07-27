/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:11:55 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/06/17 14:52:29 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Checks if a string contains only digits.
 *
 * This function takes a string and checks if all its characters are digits.
 *
 * @param str The string to check.
 * @return true if the string contains only digits, false otherwise.
 */
static bool	is_only_digits(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		i++;
	}
	return (true);
}

/**
 * @brief Validates the command-line arguments.
 *
 * This function takes the count of command-line arguments and the 
 * arguments themselves, checks if all arguments are valid positive integers, 
 * and if the first argument is within the allowed range. If an argument is 
 * invalid, it prints an error message and returns false.
 *
 * @param ac The count of command-line arguments.
 * @param av The command-line arguments.
 * @return true if all arguments are valid, false otherwise.
 */
bool	is_valid_input(int ac, char **av)
{
	int	i;
	int	nb;

	i = 1;
	while (i < ac)
	{
		if (!is_only_digits(av[i]))
			return (pme(ERR_INVALID_IN_V, av[i], false));
		nb = pos_atoi(av[i]);
		if (i == 1 && (nb <= 0 || nb > P_MAX_COUNT))
			return (pme(ERR_INVALID_IN_P, P_MAX_COUNT_S, false));
		if (i != 1 && nb == -1)
			return (pme(ERR_INVALID_IN_V, av[i], false));
		i++;
	}
	return (true);
}
