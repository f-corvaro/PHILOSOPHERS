/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:55:45 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/05/24 15:36:34 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/* ------------  LIBRARIES INCLUDED  ---------------------------------------- */

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>

/* ------------  PHILOSOPHERS HEADER FILE INCLUDED  ------------------------- */

# include "./config.h"
# include "./error_messages.h"
# include "./functions.h"
# include "./macro.h"
# include "./types.h"

#endif