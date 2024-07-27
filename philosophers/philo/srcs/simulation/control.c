/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:28:40 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/06/17 19:49:53 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Updates the stop flag of the simulation.
 *
 * This function locks the simulation stop mutex, updates the stop flag,
 * and then unlocks the mutex to ensure thread safety.
 *
 * @param table Pointer to the simulation table.
 * @param f The new value for the stop flag.
 */
static void	update_stop_flag(t_sim *table, bool f)
{
	pthread_mutex_lock(&table->sim_stop_m);
	table->sim_stop = f;
	pthread_mutex_unlock(&table->sim_stop_m);
}

/**
 * @brief Checks if a philosopher has starved to death.
 *
 * This function checks if the time since the philosopher's last meal 
 * is greater than or equal to the time it takes for a philosopher to die. 
 * If so, it updates the stop flag of the simulation table, logs the death 
 * of the philosopher, unlocks the meal time mutex, and returns true. If the 
 * philosopher has not starved, it simply returns false.
 *
 * @param philo Pointer to the philosopher structure.
 * @return true if the philosopher has starved to death, false otherwise.
 */
static bool	executioner(t_philo *philo)
{
	time_t	t;

	t = get_time_in_ms();
	if ((t - philo->last_meal) >= philo->table->time_to_die)
	{
		update_stop_flag(philo->table, true);
		log_philo_a(philo, true, DIED);
		pthread_mutex_unlock(&philo->meal_time_m);
		return (true);
	}
	return (false);
}

/**
 * @brief Checks if the end of the simulation has been reached.
 *
 * This function iterates over all philosophers in the simulation. 
 * For each philosopher, it locks the meal time mutex and checks if the 
 * philosopher has starved to death. If so, it returns true immediately. 
 * If the `must_eat_count` of the simulation table is not -1,
 * it also checks if the philosopher has eaten less than `must_eat_count` times, 
 * and if so, it sets `is_full` to false. After checking all philosophers, 
 * if `must_eat_count` is not -1 and `is_full` is true, it updates the stop flag
 * of the simulation table to true and returns true.
 * If none of these conditions are met, it returns false.
 *
 * @param table Pointer to the simulation table.
 * @return true if the end of the simulation has been reached, false otherwise.
 */
static bool	is_end_reached(t_sim *table)
{
	bool			is_full;
	unsigned int	i;

	is_full = true;
	i = 0;
	while (i < table->nb_philos)
	{
		pthread_mutex_lock(&table->philos[i]->meal_time_m);
		if (executioner(table->philos[i]))
			return (true);
		if (table->must_eat_count != -1)
			if (table->philos[i]->meal_count
				< (unsigned int)table->must_eat_count)
				is_full = false;
		pthread_mutex_unlock(&table->philos[i]->meal_time_m);
		i++;
	}
	if (table->must_eat_count != -1 && is_full == true)
	{
		update_stop_flag(table, true);
		return (true);
	}
	return (false);
}

/**
 * @brief Monitors the simulation for end conditions.
 *
 * This function continuously checks if the end condition of the simulation 
 * has been reached.
 * If the `must_eat_count` of the simulation table is zero, the function returns
 * immediately.
 * Otherwise, it updates the stop flag of the simulation to false, synchronizes 
 * the philosophers, and then enters a loop where it checks the end condition 
 * and sleeps for a short period.
 * The function returns when the end condition is reached.
 *
 * @param sim Pointer to the simulation table.
 * @return NULL always.
 */
static void	*sim_monitor(void *sim)
{
	t_sim			*table;

	table = (t_sim *)sim;
	if (table->must_eat_count == 0)
		return (NULL);
	update_stop_flag(table, false);
	sync_philo(table->t0);
	while (true)
	{
		if (is_end_reached(table) == true)
			return (NULL);
		usleep(1000);
	}
	return (NULL);
}

/**
 * @brief Initializes and starts the simulation.
 *
 * This function sets the start time of the simulation, then creates a new 
 * thread for each philosopher in the simulation. Each thread runs the 
 * `p_routine` function with the corresponding philosopher as argument.
 * If thread creation fails, it calls `init_err` with the thread creation 
 * error message and returns false. If there are more than one philosophers, 
 * it also creates a death monitor thread that runs the `sim_monitor`
 * function with the simulation table as argument. If the death monitor 
 * thread creation fails, it also calls
 * `init_err` with the thread creation error message and returns false. 
 * If all threads are created successfully,
 * it returns true.
 *
 * @param table Pointer to the simulation table.
 * @return true if all threads are created successfully, false otherwise.
 */
bool	ias_sim(t_sim *table)
{
	unsigned int	i;

	table->t0 = get_time_in_ms() + (table->nb_philos * 2 * 10);
	i = 0;
	while (i < table->nb_philos)
	{
		if (pthread_create(&table->philos[i]->thread, NULL,
				&p_routine, table->philos[i]) != 0)
			return (init_err(STR_ERR_THREAD, NULL, table));
		i++;
	}
	if (table->nb_philos > 1)
	{
		if (pthread_create(&table->death_mon, NULL,
				&sim_monitor, table) != 0)
			return (init_err(STR_ERR_THREAD, NULL, table));
	}
	return (true);
}
