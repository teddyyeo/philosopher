/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 19:23:09 by tayeo             #+#    #+#             */
/*   Updated: 2022/12/07 16:23:04 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int error(int flag, char *msg)
{
	ft_printf("%s", msg);
	if (flag == 1)
		return (1);
	return (0);
}

int set_property(int argc, char **argv, t_args *property)
{
	property->n_philo = ft_atoi(argv[1]);
	property->t_die = ft_atoi(argv[2]);
	property->t_eat = ft_atoi(argv[3]);
	property->t_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		property->n_min_meal = ft_atoi(argv[5]);
	if (property->n_philo <= 0)
		return (-1);
	return (1);
}

int	main(int argc, char **argv)
{
	t_args property;
	if (argc != 5 && argc != 6)
		return (error(1, "Argument Number Incorrect\n"));
	set_property(argc, argv, &property);
	if (property.n_philo <= 0)
		return (error(1, "Need atleast one philosopher!\n"));

	return (0);
}
