/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:21:06 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/06/17 19:56:24 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

/* ------------  ENUMS DEFINED  --------------------------------------------- */

typedef enum e_status	t_status;

/* ------------  STRUCTURES DEFINED  ---------------------------------------- */

typedef struct s_philo	t_philo;
typedef struct s_sim	t_sim;

/* ------------  FUNCTIONS DECLARED  ---------------------------------------- */

/*
 * srcs/input/manipulation.c
 */

int		pos_atoi(char *str);

/*
 * srcs/input/validation.c
 */

bool	is_valid_input(int ac, char **av);

/*
 * srcs/simulation/cleanup.c
 */

void	*free_sim_r(t_sim *table);
void	stop_and_clean(t_sim	*table);

/*
 * srcs/simulation/control.c
 */

bool	ias_sim(t_sim *table);

/*
 * srcs/simulation/init.c
 */

t_sim	*init_table(int ac, char **av, int i);

/*
 * srcs/simulation/philosopher_actions_logger.c
 */

void	log_philo_a(t_philo *philo, bool monitor, t_status status);

/*
 * srcs/simulation/philosopher_behaviour.c
 */

void	*p_routine(void *data);

/*
 * srcs/simulation/state.c
 */

bool	is_sim_stopped(t_sim *table);

/*
 * srcs/utils/error_management.c
 */

int		init_err(char *str, char *a_info, t_sim *table);
void	*init_err_v(char *str, char *a_info, t_sim *table);

/*
 * srcs/utils/message_handling.c
 */

int		pme(char *msg, char *a_info, int exit_code);

/*
 * srcs/utils/time_operations.c
 */

time_t	get_time_in_ms(void);
void	sync_philo(time_t target_time_ms);

#endif
