/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:01:42 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/06/17 19:53:42 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H	

/* ------------  STRUCTURES DEFINED  ---------------------------------------- */

typedef struct s_philo	t_philo;

/**
 * @struct t_sim
 * @brief A structure to represent the simulation with philosophers.
 *
 * @var t_sim::t0
 * Start time of the simulation.
 * 
 * @var t_sim::time_to_die
 * Time before a philosopher dies.
 * 
 * @var t_sim::time_to_eat
 * Time it takes for a philosopher to eat.
 * 
 * @var t_sim::time_to_sleep
 * Time it takes for a philosopher to sleep.
 * 
 * @var t_sim::death_mon
 * Thread to monitor death of philosophers.
 * 
 * @var t_sim::must_eat_count
 * Number of times each philosopher must eat.
 * 
 * @var t_sim::sim_stop
 * Boolean to indicate if the simulation should stop.
 * 
 * @var t_sim::sim_stop_m
 * Mutex for stopping the simulation.
 * 
 * @var t_sim::write_m
 * Mutex for writing output.
 * 
 * @var t_sim::fork_m
 * Mutex for the forks.
 * 
 * @var t_sim::philos
 * Array of philosophers.
 * 
 * @var t_sim::nb_philos
 * Number of philosophers.
 */
typedef struct s_sim
{
	time_t			t0;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	pthread_t		death_mon;
	int				must_eat_count;
	bool			sim_stop;
	pthread_mutex_t	sim_stop_m;
	pthread_mutex_t	write_m;
	pthread_mutex_t	*fork_m;
	t_philo			**philos;
	unsigned int	nb_philos;
}				t_sim;

/**
 * @struct t_philo
 * @brief  A structure to represent a philosopher in the dining philosophers 
 * problem.
 *
 * @var t_philo::thread
 * The ID of the thread associated with the philosopher.
 *
 * @var t_philo::meal_time_m
 * A mutex used to control access to the philosopher's meal times.
 *
 * @var t_philo::last_meal
 * The time of the philosopher's last meal.
 *
 * @var t_philo::id
 * The ID of the philosopher.
 *
 * @var t_philo::meal_count
 * The number of meals the philosopher has eaten.
 *
 * @var t_philo::fork[2]
 * The IDs of the forks the philosopher can use.
 *
 * @var t_philo::table
 * A pointer to the table at which the philosopher is dining.
 */
typedef struct s_philo
{
	pthread_t			thread;
	pthread_mutex_t		meal_time_m;
	time_t				last_meal;
	unsigned int		id;
	unsigned int		meal_count;
	unsigned int		fork[2];
	t_sim				*table;
}				t_philo;

/* ------------  ENUMERATIONS DEFINED  -------------------------------------- */

/**
 * @brief Representing the status of a philosopher. Chosen arbitrarily.
 *
 * Each philosopher can be in one of the following states:
 * - DIED: The philosopher has died.
 * - EATING: The philosopher is eating.
 * - SLEEPING: The philosopher is sleeping.
 * - THINKING: The philosopher is thinking.
 * - GOT_L_FORK: The philosopher has picked up the left fork.
 * - GOT_R_FORK: The philosopher has picked up the right fork.
 */
typedef enum e_status
{
	DIED = 1,
	EATING = 2,
	SLEEPING = 4,
	THINKING = 8,
	GOT_L_FORK = 16,
	GOT_R_FORK = 32
}			t_status;

#endif