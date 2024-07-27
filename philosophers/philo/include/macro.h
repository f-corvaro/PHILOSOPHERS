/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:13:10 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/06/17 16:27:50 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACRO_H
# define MACRO_H

/**
 * @def BUILD_INFO
 * @brief Prefix for build information messages.
 */
# define BUILD_INFO	"philo:"

/* ------------  PHILOSOPHERS' ACTIONS -------------------------------------- */

/** 
 * @def P_DIED
 * @brief A macro that represents the "died" action of a philosopher.
 */
# define P_DIED "died"

/** 
 * @def P_EATING
 * @brief A macro that represents the "is eating" action of a philosopher.
 */
# define P_EATING "is eating"

/** 
 * @def P_SLEEPING
 * @brief A macro that represents the "is sleeping" action of a philosopher.
 */
# define P_SLEEPING "is sleeping"

/** 
 * @def P_TAKEN_FORK
 * @brief A macro that represents the "has taken a fork" action of a philosopher.
 */
# define P_TAKEN_FORK "has taken a fork"

/** 
 * @def P_THINKING
 * @brief A macro that represents the "is thinking" action of a philosopher.
 */
# define P_THINKING "is thinking"

#endif
