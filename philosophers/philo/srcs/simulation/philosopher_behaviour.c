/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_behaviour.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:30:28 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/06/17 19:22:54 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Simulates a philosopher sleeping for a certain amount of time.
 *
 * @param table Pointer to the simulation table.
 * @param nap The amount of time the philosopher should sleep, in milliseconds.
 *
 * The function calculates the time at which the philosopher should wake up,
 * and then enters a loop where it continually checks whether this time has been 
 * reached. 
 * If the simulation has stopped, it breaks out of the loop.
 */
static void	sleeping(t_sim *table, time_t nap)
{
	time_t	alarm_clock;

	alarm_clock = get_time_in_ms() + nap;
	while (get_time_in_ms() < alarm_clock)
	{
		if (is_sim_stopped(table))
			break ;
		usleep(100);
	}
}

/**
 * @brief Simulates half of a philosopher's routine 
 * (sleeping and eating).
 *
 * @param philo Pointer to the philosopher structure.
 *
 * The function simulates the philosopher picking up the left fork, then the 
 * right fork, eating for a certain amount of time, and then putting down the 
 * forks. 
 * If the simulation has not stopped, the philosopher's meal count is 
 * incremented. 
 * The philosopher then sleeps for a certain amount of time.
 */
static void	half_routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->fork_m[philo->fork[0]]);
	log_philo_a(philo, false, GOT_L_FORK);
	pthread_mutex_lock(&philo->table->fork_m[philo->fork[1]]);
	log_philo_a(philo, false, GOT_R_FORK);
	log_philo_a(philo, false, EATING);
	pthread_mutex_lock(&philo->meal_time_m);
	philo->last_meal = get_time_in_ms();
	pthread_mutex_unlock(&philo->meal_time_m);
	sleeping(philo->table, philo->table->time_to_eat);
	if (is_sim_stopped(philo->table) == false)
	{
		pthread_mutex_lock(&philo->meal_time_m);
		philo->meal_count += 1;
		pthread_mutex_unlock(&philo->meal_time_m);
	}
	log_philo_a(philo, false, SLEEPING);
	pthread_mutex_unlock(&philo->table->fork_m[philo->fork[1]]);
	pthread_mutex_unlock(&philo->table->fork_m[philo->fork[0]]);
	sleeping(philo->table, philo->table->time_to_sleep);
}

/**
 * @brief Simulates a philosopher's thinking action.
 *
 * @param philo Pointer to the philosopher structure.
 * @param f Boolean flag to control logging of the philosopher's actions.
 *
 * The function calculates the duration for which the philosopher should think. 
 * This is done by subtracting the time since the philosopher's last meal and 
 * the time it takes to eat from the time at which the philosopher is supposed 
 * to die, and then dividing the result by 2.
 * The philosopher then sleeps (thinks) for the calculated duration.
 */
static void	thinking(t_philo *philo, bool f)
{
	time_t	duration;

	pthread_mutex_lock(&philo->meal_time_m);
	duration = (philo->table->time_to_die
			- (get_time_in_ms() - philo->last_meal)
			- philo->table->time_to_eat) / 2;
	pthread_mutex_unlock(&philo->meal_time_m);
	if (duration < 0)
		duration = 0;
	if (duration == 0 && f == true)
		duration = 1;
	if (duration > 600)
		duration = 200;
	if (f == false)
		log_philo_a(philo, false, THINKING);
	sleeping(philo->table, duration);
}

/**
 * @brief This function is invoked when there is only a single philosopher.
 * 
 * A single philosopher only has one fork, and so cannot eat. The philosopher 
 * will pick up that fork, wait and die. 
 * 
 * @param philo Pointer to the philosopher structure.
 * 
 * @return Returns NULL.
 */
static void	*a_single_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->fork_m[philo->fork[0]]);
	log_philo_a(philo, false, GOT_L_FORK);
	sleeping(philo->table, philo->table->time_to_die);
	log_philo_a(philo, false, DIED);
	pthread_mutex_unlock(&philo->table->fork_m[philo->fork[0]]);
	return (NULL);
}

/**
 * @brief Function representing the behavior of a philosopher.
 *
 * @param data A void pointer to the philosopher's data, which is 
 * cast to a t_philo pointer.
 * @return NULL if the philosopher's table's must_eat_count or time_to_die is 0,
 * or if the simulation has stopped.
 * Otherwise, it returns the result of a_single_philo function if the number 
 * of philosophers is 1, or it runs the philosopher's routine in a loop until 
 * the simulation stops.
 */
void	*p_routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (philo->table->must_eat_count == 0)
		return (NULL);
	pthread_mutex_lock(&philo->meal_time_m);
	philo->last_meal = philo->table->t0;
	pthread_mutex_unlock(&philo->meal_time_m);
	sync_philo(philo->table->t0);
	if (philo->table->time_to_die == 0)
		return (NULL);
	if (philo->table->nb_philos == 1)
		return (a_single_philo(philo));
	else if (philo->id % 2)
		thinking(philo, true);
	while (is_sim_stopped(philo->table) == false)
	{
		half_routine(philo);
		thinking(philo, false);
	}
	return (NULL);
}
