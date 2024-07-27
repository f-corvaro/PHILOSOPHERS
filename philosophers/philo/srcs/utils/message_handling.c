/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_handling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:51:57 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/05/24 12:56:29 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Prints a message and returns an exit code.
 *
 * This function takes a message and an optional additional information string,
 * formats the message using the BUILD_INFO macro and the additional 
 * information, prints the message, and then returns the provided exit code.
 *
 * @param msg The main message to be printed.
 * @param a_info Additional information to be included in the message. 
 * If NULL, no additional information is included.
 * @param exit_code The exit code to be returned by the function.
 * @return The provided exit code.
 */
int	pme(char *msg, char *a_info, int exit_code)
{
	if (!a_info)
		printf(msg, BUILD_INFO);
	else
		printf(msg, BUILD_INFO, a_info);
	return (exit_code);
}
