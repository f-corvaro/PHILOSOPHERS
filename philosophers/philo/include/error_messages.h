/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:42:45 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/06/17 19:36:41 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MESSAGES_H
# define ERROR_MESSAGES_H

/* ------------  INPUT ERROR MESSAGES DEFINED  ------------------------------ */

/**
 * @def ERR_INVALID_IN_V
 * @brief Error message for invalid input value.
 *
 * This macro defines an error message that is displayed when the input is not
 * a valid unsigned integer.
 */
# define ERR_INVALID_IN_V \
	"%s ERROR: Invalid input value: %s: \
	Not a valid unsigned integer. Allowed value between 0 and 2147483647.\n"

/**
 * @def ERR_INVALID_IN_P
 * @brief Error message for invalid philosopher count.
 *
 * This macro defines an error message that is displayed when the input 
 * value for the number of philosophers is invalid.
 */
# define ERR_INVALID_IN_P \
	"%s ERROR: Invalid input value: \
	The number of philosophers must be between 1 and %s philosophers.\n"

/**
 * @def ERR_USAGE
 * @brief Error message for invalid usage.
 *
 * This macro defines an error message that is displayed when the program 
 * is used incorrectly.
 */
# define ERR_USAGE	\
	"%s ERROR: Invalid usage. Run 'make usage' for more info. \n"

/* ------------  THREAD AND MEMORY ERROR MESSAGES --------------------------- */

/**
 * @def STR_ERR_MALLOC
 * @brief Error message for a memory allocation problem.
 *
 */
# define STR_ERR_MALLOC	"%s ERROR: Failed to allocate memory correctly.\n"

/**
 * @def STR_ERR_MUTEX
 * @brief Error message for a mutex initialization problem.
 *
 */
# define STR_ERR_MUTEX	"%s ERROR: Mutex initialization failed.\n"

/**
 * @brief Error message for thread creation failure.
 *
 */
# define STR_ERR_THREAD	"%s ERROR: Thread creation failed.\n"

#endif