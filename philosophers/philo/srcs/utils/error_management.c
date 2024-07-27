/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:42:32 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/06/17 16:15:32 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Handles an error, frees the simulation table if it's not NULL, 
 * and logs an error message.
 * 
 * @param str The error message to be logged.
 * @param a_info Additional information to be logged with the error message.
 * @param table The simulation table to be freed if it's not NULL.
 * 
 * @return Returns the result of the pme function.
 */
int	init_err(char *str, char *a_info, t_sim *table)
{
	if (table != NULL)
		free_sim_r(table);
	return (pme(str, a_info, 0));
}

/**
 * @brief Handles an error, frees the simulation table if it's not NULL, 
 * logs an error message, and returns NULL.
 * 
 * @param str The error message to be logged.
 * @param a_info Additional information to be logged with the error message.
 * @param table The simulation table to be freed if it's not NULL.
 * 
 * @return Returns NULL.
 */
void	*init_err_v(char *str, char *a_info, t_sim *table)
{
	if (table != NULL)
		free_sim_r(table);
	pme(str, a_info, EXIT_FAILURE);
	return (NULL);
}
