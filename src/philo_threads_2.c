/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threads_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 20:28:06 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/09/24 21:45:52 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

bool	is_simulation_over(t_philo *philo, struct timeval *begin)
{
	t_philo_data	*pdata;
	struct timeval	now;
	unsigned long	diff;

	gettimeofday(&now, NULL);
	pdata = get_philo_data();
	diff = (now.tv_sec - philo->last_time_eat.tv_sec) * 1000
		+ (now.tv_usec - philo->last_time_eat.tv_usec) / 1000;
	if (pdata->end_simulation || (diff >= pdata->eat_time))
	{
		if (!pdata->end_simulation)
		{
			pdata->end_simulation = true;
			philo_log(philo->index, begin, die);
		}
		if (philo->left.status == philo->index)
			pthread_mutex_unlock(philo->left.mutex_ptr);
		if (philo->right.status == philo->index)
			pthread_mutex_unlock(philo->right.mutex_ptr);
		return (true);
	}
	return (false);
}
