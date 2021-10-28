/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_data.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 21:44:29 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/09/24 20:58:36 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_DATA_H
# define PHILO_DATA_H

# include <stdbool.h>
# include <sys/time.h>
# include <pthread.h>

# define NO_EAT_CNT ((unsigned int)-1)

typedef struct s_philo_data {
	unsigned int		eat_time;
	unsigned int		sleep_time;
	unsigned int		think_time;
	unsigned int 		eat_cnt;
	pthread_mutex_t		write_mutex;
	pthread_mutex_t		global_fork_mutex;
	volatile bool		end_simulation;
}	t_philo_data;

t_philo_data	*get_philo_data(void);
void			set_philo_data(unsigned int eat_time, unsigned int sleep_time,
					unsigned int think_time, unsigned int eat_cnt);
void			set_begin_time(void);
void			destroy_data_mutex(void);

#endif
