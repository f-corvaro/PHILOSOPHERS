/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:06:46 by fcorvaro          #+#    #+#             */
/*   Updated: 2024/06/17 19:44:20 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_sim	*dining_table;

	dining_table = NULL;
	if (ac - 1 < 4 || ac - 1 > 5)
		return (pme(ERR_USAGE, NULL, EXIT_FAILURE));
	if (!is_valid_input(ac, av))
		return (EXIT_FAILURE);
	dining_table = init_table(ac, av, 1);
	if (!dining_table)
		return (EXIT_FAILURE);
	if (!ias_sim(dining_table))
		return (EXIT_FAILURE);
	stop_and_clean(dining_table);
	return (EXIT_SUCCESS);
}
