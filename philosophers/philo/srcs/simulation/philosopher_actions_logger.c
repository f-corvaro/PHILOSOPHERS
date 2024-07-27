/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_actions_logger.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:31:43 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/06/17 19:55:53 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Prints the action of a philosopher.
 * 
 * @param philo The philosopher whose action is being printed.
 * @param str The action to be printed.
 */
static void	print_philo_action(t_philo *philo, char *str)
{
	printf("%ld %d %s\n", get_time_in_ms() - philo->table->t0,
		philo->id + 1, str);
}

/**
 * @brief Logs the action of a philosopher.
 * 
 * @param philo The philosopher whose action is being logged.
 * @param monitor A boolean indicating whether the monitor is reporting.
 * @param status The status of the philosopher.
 */
void	log_philo_a(t_philo *philo, bool monitor, t_status status)
{
	pthread_mutex_lock(&philo->table->write_m);
	if (monitor == false && is_sim_stopped(philo->table) == true)
	{
		pthread_mutex_unlock(&philo->table->write_m);
		return ;
	}
	if (status == DIED)
		print_philo_action(philo, P_DIED);
	else if (status == EATING)
		print_philo_action(philo, P_EATING);
	else if (status == SLEEPING)
		print_philo_action(philo, P_SLEEPING);
	else if (status == THINKING)
		print_philo_action(philo, P_THINKING);
	else if (status == GOT_L_FORK || status == GOT_R_FORK)
		print_philo_action(philo, P_TAKEN_FORK);
	pthread_mutex_unlock(&philo->table->write_m);
}
