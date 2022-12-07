/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 19:26:31 by tayeo             #+#    #+#             */
/*   Updated: 2022/12/07 02:05:35 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <sys/time.h>
# include <pthread.h>
# include "ft_printf.h"

typedef struct s_args
{
	int n_philo;
	int t_die;
	int t_eat;
	int t_sleep;
	int n_min_meal;
}	t_args;

int	ft_atoi(const char *str);

#endif
