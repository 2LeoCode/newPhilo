/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 21:23:46 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/09/24 22:00:39 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "philo_data.h"
# include "philo_thread.h"

# include <pthread.h>
# include <unistd.h>

typedef struct s_fork_set {
	size_t			cnt;
	pthread_mutex_t	forks[];
}	t_fork_set;

typedef struct s_fork {
	volatile unsigned int	status;
	pthread_mutex_t			*mutex_ptr;
}	t_fork;

typedef struct s_philo {
	pthread_t		thread;
	pthread_t		wrapper_thread;
	unsigned int	index;
	t_fork			left;
	t_fork			right;
	struct timeval	last_time_eat;
	unsigned int	eat_cnt;
}	t_philo;

#endif
