/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:37:45 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/06/17 17:51:46 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Gets the current time in milliseconds.
 *
 * This function uses the gettimeofday function to get the current time, 
 * in seconds (tv_sec) and microseconds (tv_usec) since the Epoch 
 * (1970-01-01 00:00:00 +0000 UTC), then converts it to milliseconds 
 * and returns the result.
 *
 * @return The current time in milliseconds.
 */
time_t	get_time_in_ms(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

/**
 * @brief Synchronizes the start of philosopher threads.
 * 
 * @param target_time_ms The start time in milliseconds at which the threads 
 * should start.
 */
void	sync_philo(time_t target_time_ms)
{
	while (get_time_in_ms() < target_time_ms)
		continue ;
}
