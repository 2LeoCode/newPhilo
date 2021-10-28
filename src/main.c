/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 21:54:20 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/09/24 21:58:51 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>
#include <exceptions.h>
#include <utils.h>
#include <stdlib.h>


bool	valid_arguments(int ac, const char **const av)
{
	int	i = 1;

	while (i < ac && ft_strisdigit(av[i]))
		++i;
	return (i == ac);
}
#include <stdio.h>
t_fork_set	*get_fork_set(unsigned int cnt)
{
	t_fork_set	*fork_set;


	fork_set = malloc(sizeof(t_fork_set) + sizeof(pthread_mutex_t) * cnt);
	if (fork_set)
	{
		fork_set->cnt = cnt;
		while (cnt--)
		{
			printf("%u\n", cnt);
			pthread_mutex_init(&fork_set->forks[cnt], NULL);
		}
	}
	return (fork_set);
}

void	destroy_fork_set(t_fork_set *set)
{
	while (set->cnt--)
		pthread_mutex_destroy(&set->forks[set->cnt]);
	free(set);
}

int	create_new_philo(pthread_mutex_t *left_fork, pthread_mutex_t *right_fork)
{
	static unsigned int	index;
	t_philo				new_philo;

	new_philo.index = ++index;
	new_philo.left = (t_fork){ false, left_fork };
	new_philo.right = (t_fork){ false, right_fork };
	if (pthread_create(&new_philo.wrapper_thread, NULL, philo_thread_wrapper, &new_philo))
		return (-1);
	pthread_detach(new_philo.wrapper_thread);
	return (0);
}

int	create_philos(unsigned int cnt, t_fork_set *fork_set)
{
	unsigned int	i;

	i = (unsigned int)-1;
	while (++i < cnt - 1)
		if (create_new_philo(&fork_set->forks[i], &fork_set->forks[i + 1]))
		{
			destroy_fork_set(fork_set);
			return (-1);
		}
	if (create_new_philo(&fork_set->forks[i], &fork_set->forks[0]))
	{
		destroy_fork_set(fork_set);
		return (-1);
	}
	return (0);
}

int	main(int argc, const char **const argv)
{
	unsigned int	philo_cnt;
	t_fork_set		*fork_set;
	t_philo_data	*philo_data;

	if ((argc != 5 && argc != 6) || !valid_arguments(argc, argv))
		return (except_invalid_arguments(argv[0]));
	philo_cnt = ft_atol(argv[1]);
	if (!philo_cnt)
		return (0);
	if (argc == 6)
		set_philo_data(philo_cnt, ft_atol(argv[2]), ft_atol(argv[3]),
			ft_atol(argv[4]));
	else
		set_philo_data(philo_cnt, ft_atol(argv[2]), ft_atol(argv[3]),
			NO_EAT_CNT);
	fork_set = get_fork_set(philo_cnt);
	if (!fork_set)
		return (except_no_memory());
	if (create_philos(philo_cnt, fork_set))
		return (except_thread_fail());
	philo_data = get_philo_data();
	while (!philo_data->end_simulation)
		usleep(2000);
	destroy_fork_set(fork_set);
	destroy_data_mutex();
	return (0);
}
