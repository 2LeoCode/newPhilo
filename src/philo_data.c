/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 17:21:01 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/09/24 21:12:37 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_data.h>

#include <sys/time.h>
#include <stddef.h>

static t_philo_data	*philo_data(const t_philo_data *data)
{
	static t_philo_data		current_data;

	if (data)
		current_data = *data;
	else
		return (&current_data);
	return (NULL);
}

t_philo_data	*get_philo_data(void)
{
	return (philo_data(NULL));
}

void	set_philo_data(unsigned int eat_time, unsigned int sleep_time,
			unsigned int think_time, unsigned int eat_cnt)
{
	const t_philo_data	pdata = {
		.eat_time = eat_time,
		.sleep_time = sleep_time,
		.think_time = think_time,
		.eat_cnt = eat_cnt,
		.end_simulation = false,
		.write_mutex = PTHREAD_MUTEX_INITIALIZER,
		.global_fork_mutex = PTHREAD_MUTEX_INITIALIZER
	};
	philo_data(&pdata);
}

void	destroy_data_mutex(void)
{
	t_philo_data	*pdata = get_philo_data();

	pthread_mutex_lock(&pdata->write_mutex);
	pthread_mutex_unlock(&pdata->write_mutex);
	pthread_mutex_destroy(&pdata->write_mutex);
	pthread_mutex_destroy(&pdata->global_fork_mutex);
}
