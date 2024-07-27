/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:35:48 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/06/17 15:45:39 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Destroys the simulation mutexes.
 * 
 * This function destroys all the mutexes that were created for the simulation.
 * It destroys the mutexes for the forks, the meal times of each philosopher,
 * the output writing, and the simulation stopping.
 * 
 * @param table A pointer to the simulation table structure.
 */
static void	destroy_sim_m(t_sim *table)
{
	unsigned int	i;

	i = 0;
	while (i < table->nb_philos)
	{
		pthread_mutex_destroy(&table->fork_m[i]);
		pthread_mutex_destroy(&table->philos[i]->meal_time_m);
		i++;
	}
	pthread_mutex_destroy(&table->write_m);
	pthread_mutex_destroy(&table->sim_stop_m);
}

/**
 * @brief Frees the simulation resources.
 * 
 * This function frees all the resources that were allocated for the simulation.
 * It frees the array of forks, the array of philosophers, and the simulation 
 * table itself.
 * 
 * @param table A pointer to the simulation table structure.
 * 
 * @return NULL always.
 */
void	*free_sim_r(t_sim *table)
{
	unsigned int	i;

	if (!table)
		return (NULL);
	if (table->fork_m != NULL)
		free(table->fork_m);
	if (table->philos != NULL)
	{
		i = 0;
		while (i < table->nb_philos)
		{
			if (table->philos[i] != NULL)
				free(table->philos[i]);
			i++;
		}
		free(table->philos);
	}
	free(table);
	return (NULL);
}

/**
 * @brief Stops all threads and cleans up the simulation.
 *
 * This function stops all philosopher threads in the simulation by joining 
 * them.
 * If there are more than one philosophers, it also stops the death monitor 
 * thread.
 * After stopping all threads, it destroys the simulation mutexes and frees 
 * the simulation resources.
 *
 * @param table The simulation table containing all the simulation data.
 */
void	stop_and_clean(t_sim	*table)
{
	unsigned int	i;

	i = 0;
	while (i < table->nb_philos)
	{
		pthread_join(table->philos[i]->thread, NULL);
		i++;
	}
	if (table->nb_philos > 1)
		pthread_join(table->death_mon, NULL);
	destroy_sim_m(table);
	free_sim_r(table);
}
