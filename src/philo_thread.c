/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 23:02:36 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/09/24 21:35:29 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static int	philo_eat(t_philo *philo, struct timeval *begin)
{
	t_philo_data	*pdata;
	bool			got_forks;

	pdata = get_philo_data();
	got_forks = false;
	while (!got_forks)
	{
		pthread_mutex_lock(&pdata->global_fork_mutex);
		if (is_simulation_over(philo, begin))
			return (-1);
		if (!philo->left.status && !philo->right.status)
		{
			philo->left.status = philo->index;
			philo->right.status = philo->index;
			philo_log(philo->index, begin, take_fork);
			philo_log(philo->index, begin, take_fork);
			pthread_mutex_lock(philo->left.mutex_ptr);
			pthread_mutex_lock(philo->right.mutex_ptr);
			got_forks = true;
		}
		pthread_mutex_unlock(&pdata->global_fork_mutex);
	}
	gettimeofday(&philo->last_time_eat, NULL);
	if (is_simulation_over(philo, begin))
		return (-1);
	philo_log(philo->index, begin, eat);
	usleep(pdata->eat_time * 1000);
	if (is_simulation_over(philo, begin))
		return (-1);
	return (0);
}

static int	philo_sleep(t_philo *philo, struct timeval *begin)
{
	t_philo_data	*pdata;

	pdata = get_philo_data();
	pthread_mutex_unlock(philo->left.mutex_ptr);
	philo->left.status = 0;
	pthread_mutex_unlock(philo->right.mutex_ptr);
	philo->right.status = 0;
	philo_log(philo->index, begin, fall_asleep);
	usleep(pdata->sleep_time * 1000);
	if (is_simulation_over(philo, begin))
		return (-1);
	return (0);
}

static int	philo_think(t_philo *philo, struct timeval *begin)
{
	t_philo_data	*pdata;

	pdata = get_philo_data();
	pthread_mutex_unlock(philo->left.mutex_ptr);
	philo->left.status = false;
	pthread_mutex_unlock(philo->right.mutex_ptr);
	philo->right.status = false;
	philo_log(philo->index, begin, think);
	usleep(pdata->think_time * 1000);
	if (is_simulation_over(philo, begin))
		return (-1);
	return (0);
}

void	*philo_thread_wrapper(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (pthread_create(&philo->thread, NULL, philo_thread, data))
		return (((void *)-1));
	pthread_join(philo->thread, NULL);
	return (NULL);
}

void	*philo_thread(void *data)
{
	t_philo			*philo;
	t_philo_data	*philo_data;
	struct timeval	begin;

	philo = (t_philo *)data;
	philo_data = get_philo_data();
	gettimeofday(&begin, NULL);
	philo->last_time_eat = begin;
	while (true)
	{
		if (philo_eat(philo, &begin) || philo_sleep(philo, &begin)
				|| philo_think(philo, &begin))
			break ;
	}
	return (NULL);
}
