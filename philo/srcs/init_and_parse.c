#include "../include/philo.h"

int	is_num(char **argv)
{
	int	i;
	int	j;

	j = 1;
	while (argv[j])
	{
		i = 0;
		while (argv[j][i])
		{
			if (argv[j][i] < '0' || argv[j][i] > '9')
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int	parse_args(int argc, char **argv, t_data *p)
{
	if ((argc == 5 || argc == 6) && is_num(argv))
	{
		p->arg.n_philo = ft_atoi(argv[1]);
		p->arg.die = ft_atoi(argv[2]);
		p->arg.eat = ft_atoi(argv[3]);
		p->arg.sleep = ft_atoi(argv[4]);
		p->arg.m_eat = -1;
		if (argc == 6)
			p->arg.m_eat = ft_atoi(argv[5]);
		if (p->arg.n_philo <= 0 || p->arg.die <= 0 || p->arg.eat <= 0 \
			|| p->arg.sleep <= 0)
			return (0);
		return (1);
	}
	return (0);
}

void	init_mutex(t_data *p)
{
	pthread_mutex_init(&p->arg.write_mutex, NULL);
	pthread_mutex_init(&p->arg.dead, NULL);
	pthread_mutex_init(&p->arg.time_eat, NULL);
	pthread_mutex_init(&p->arg.finish, NULL);
}

int	initialize(t_data *p)
{
	int	i;

	i = 0;
	p->arg.start_t = actual_time();
	p->arg.stop = 0;
	p->arg.nb_p_finish = 0;
	init_mutex(p);
	while (i < p->arg.n_philo)
	{
		p->philo[i].id = i + 1;
		p->philo[i].ms_eat = p->arg.start_t;
		p->philo[i].nb_eat = 0;
		p->philo[i].finish = 0;
		p->philo[i].r_f = NULL;
		pthread_mutex_init(&p->philo[i].l_f, NULL);
		if (p->arg.n_philo == 1)
			return (1);
		if (i == p->arg.n_philo - 1)
			p->philo[i].r_f = &p->philo[0].l_f;
		else
			p->philo[i].r_f = &p->philo[i + 1].l_f;
		i++;
	}
	return (1);
}
