/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:32:37 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/06/17 15:57:11 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Initializes the mutexes representing the forks.
 * 
 * This function allocates and initializes a number of mutexes equal to the 
 * number of philosophers. Each mutex represents a fork on the table.
 * 
 * If memory allocation fails, the function returns an error. 
 * If mutex initialization fails, the function also returns an error.
 * 
 * @param table The simulation state, including the number of philosophers 
 * (and thus forks).
 * @return A pointer to the array of initialized mutexes, or NULL if an error
 * occurred.
 */
static pthread_mutex_t	*init_forks(t_sim *table)
{
	pthread_mutex_t	*forks_m;
	unsigned int	i;

	forks_m = malloc(sizeof(pthread_mutex_t) * table->nb_philos);
	if (!forks_m)
		return (init_err_v(STR_ERR_MALLOC, NULL, 0));
	i = 0;
	while (i < table->nb_philos)
	{
		if (pthread_mutex_init(&forks_m[i], 0) != 0)
			return (init_err_v(STR_ERR_MUTEX, NULL, 0));
		i++;
	}
	return (forks_m);
}

/**
 * @brief Initializes the control mutexes for the simulation.
 * 
 * This function initializes the mutexes that control various aspects 
 * of the simulation.
 * It initializes the mutexes for the forks, the output writing, and 
 * the simulation stopping.
 * 
 * @param table A pointer to the simulation table structure.
 * 
 * @return true if all mutexes were successfully initialized, false otherwise.
 */
static bool	init_control_mutexes(t_sim *table)
{
	table->fork_m = init_forks(table);
	if (!table->fork_m)
		return (false);
	if (pthread_mutex_init(&table->write_m, 0) != 0)
		return (init_err(STR_ERR_MUTEX, NULL, table));
	if (pthread_mutex_init(&table->sim_stop_m, 0) != 0)
		return (init_err(STR_ERR_MUTEX, NULL, table));
	return (true);
}

/**
 * @brief Allocates two fork ids to each philosopher.
 * 
 * Philosophers with even ids have their fork order reversed. 
 * This is crucial because the sequence in which
 * philosophers pick up their forks is significant.
 * 
 * Consider a scenario with 3 philosophers:
 *   - Philosopher #1 (id: 0) will need fork 0 and fork 1
 *   - Philosopher #2 (id: 1) will need fork 1 and fork 2
 *   - Philosopher #3 (id: 2) will need fork 2 and fork 0
 * 
 * If philosopher #1 picks up fork 0, philosopher #2 picks up fork 1 
 * and philosopher #3 picks up fork 2, a deadlock occurs. Each will be waiting 
 * for their second fork which is currently in use by another philosopher.
 * 
 * To prevent this, even id philosophers are made "left-handed":
 *   - Philosopher #1 (id: 0) picks up fork 1 and then fork 0
 *   - Philosopher #2 (id: 1) picks up fork 1 and then fork 2
 *   - Philosopher #3 (id: 2) picks up fork 0 and then fork 2
 * 
 * In this scenario, philosopher #1 picks up fork 1, philosopher #3 picks up 
 * fork 0 and philosopher #2 waits.
 * Fork 2 is available for philosopher #3 to pick up, allowing him to eat. 
 * Once he finishes, philosopher #1 can
 * pick up fork 0 and eat. After he finishes, philosopher #2 can finally pick 
 * up fork 1 and eat.
 *  
 * @param philo The philosopher to whom the forks are being allocated.
 */
static void	assign_philo_forks(t_philo *philo)
{
	philo->fork[0] = philo->id;
	philo->fork[1] = (philo->id + 1) % philo->table->nb_philos;
	if (philo->id % 2)
	{
		philo->fork[0] = (philo->id + 1) % philo->table->nb_philos;
		philo->fork[1] = philo->id;
	}
}

/**
 * @brief Initializes the philosophers for the simulation.
 * 
 * This function allocates and initializes an array of philosophers for the 
 * simulation.
 * Each philosopher is assigned an ID, a reference to the simulation table, 
 * and their forks.
 * The function also initializes a mutex for each philosopher's meal time.
 * 
 * @param table A pointer to the simulation table structure.
 * 
 * @return A pointer to the array of philosophers if successful, 
 * NULL otherwise.
 */
static t_philo	**init_philos(t_sim *table)
{
	t_philo			**philos;
	unsigned int	i;

	philos = malloc(sizeof(t_philo) * table->nb_philos);
	if (!philos)
		return (init_err_v(STR_ERR_MALLOC, NULL, 0));
	i = 0;
	while (i < table->nb_philos)
	{
		philos[i] = malloc(sizeof(t_philo) * 1);
		if (!philos[i])
			return (init_err_v(STR_ERR_MALLOC, NULL, 0));
		if (pthread_mutex_init(&philos[i]->meal_time_m, 0) != 0)
			return (init_err_v(STR_ERR_MUTEX, NULL, 0));
		philos[i]->meal_count = 0;
		philos[i]->id = i;
		philos[i]->table = table;
		assign_philo_forks(philos[i]);
		i++;
	}
	return (philos);
}

/**
 * @brief Initializes the simulation table.
 * 
 * This function allocates and initializes a simulation table structure.
 * It sets the number of philosophers, the time to die, the time to eat, 
 * the time to sleep, and the number of times each philosopher must eat.
 * It also initializes the philosophers and the control mutexes.
 * 
 * @param ac The argument count.
 * @param av The argument vector.
 * @param i The starting index in the argument vector.
 * 
 * @return A pointer to the initialized simulation table if successful, 
 * NULL otherwise.
 */
t_sim	*init_table(int ac, char **av, int i)
{
	t_sim	*table;

	table = malloc(sizeof(t_sim) * 1);
	if (!table)
		return (init_err_v(STR_ERR_MALLOC, NULL, 0));
	table->nb_philos = pos_atoi(av[i++]);
	table->time_to_die = pos_atoi(av[i++]);
	table->time_to_eat = pos_atoi(av[i++]);
	table->time_to_sleep = pos_atoi(av[i++]);
	table->must_eat_count = -1;
	if (ac == 6)
		table->must_eat_count = pos_atoi(av[i]);
	table->philos = init_philos(table);
	if (!table->philos)
		return (NULL);
	if (!init_control_mutexes(table))
		return (NULL);
	table->sim_stop = false;
	return (table);
}
