/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_log.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 19:52:40 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/09/24 21:52:25 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_data.h>
#include <utils.h>

#include <stddef.h>
#include <sys/time.h>
#include <unistd.h>

void	eat(void)
{
	write(1, "is eating\n", 10);
}

void	fall_asleep(void)
{
	write(1, "is sleeping\n", 12);
}

void	take_fork(void)
{
	write(1, "has taken a fork\n", 17);
}

void	think(void)
{
	write(1, "is thinking\n", 12);
}

void	die(void)
{
	write(1, "died\n", 5);
}

void	philo_log(unsigned int id, struct timeval *begin, void (*printfun)(void))
{
	t_philo_data	*pdata;
	unsigned int	timestamp_in_ms;
	struct timeval	now;
	

	gettimeofday(&now, NULL);
	timestamp_in_ms = (now.tv_sec - begin->tv_sec) * 1000
		+ (now.tv_usec - begin->tv_usec) / 1000;
	pdata = get_philo_data();
	pthread_mutex_lock(&pdata->write_mutex);
	ft_print_unsigned(timestamp_in_ms);
	write(1, " ", 1);
	ft_print_unsigned(id);
	write(1, " ", 1);
	printfun();
	pthread_mutex_unlock(&pdata->write_mutex);
}
