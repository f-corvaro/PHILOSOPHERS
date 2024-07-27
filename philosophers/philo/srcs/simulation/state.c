/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:21:31 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/06/17 19:24:22 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Checks if the simulation has stopped.
 *
 * This function locks the simulation stop mutex, checks if the simulation 
 * has stopped and then unlocks the mutex. It returns true if the simulation 
 * has stopped and false otherwise.
 *
 * @param table A pointer to the simulation table structure.
 * @return true if the simulation has stopped, false otherwise.
 */
bool	is_sim_stopped(t_sim *table)
{
	bool	r;

	r = false;
	pthread_mutex_lock(&table->sim_stop_m);
	if (table->sim_stop == true)
		r = true;
	pthread_mutex_unlock(&table->sim_stop_m);
	return (r);
}
