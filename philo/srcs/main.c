#include "../include/philo.h"

int	ft_exit(char *str)
{
	printf("Error: %s", str);
	return (0);
}

int	check_death2(t_data *p)
{
	pthread_mutex_lock(&p->arg.dead);
	if (p->arg.stop)
	{
		pthread_mutex_unlock(&p->arg.dead);
		return (1);
	}
	pthread_mutex_unlock(&p->arg.dead);
	return (0);
}

void	stop(t_data *p)
{
	int	i;

	i = -1;
	while (!check_death2(p))
		ft_usleep(1);
	while (++i < p->arg.n_philo)
		pthread_join(p->philo[i].thread_id, NULL);
	pthread_mutex_destroy(&p->arg.write_mutex);
	i = -1;
	while (++i < p->arg.n_philo)
		pthread_mutex_destroy(&p->philo[i].l_f);
	if (p->arg.stop == 2)
		printf("Each philosopher ate %d time(s)\n", p->arg.m_eat);
	free(p->philo);
}

int	main(int argc, char **argv)
{
	t_data		p;

	if (!(parse_args(argc, argv, &p)))
		return (ft_exit("Invalid Arguments\n"));
	p.philo = malloc(sizeof(t_philo) * p.arg.n_philo);
	if (!p.philo)
		return (ft_exit("Malloc returned NULL\n"));
	if (!initialize(&p) || !threading(&p))
	{
		free(p.philo);
		return (0);
	}
	stop(&p);
}
