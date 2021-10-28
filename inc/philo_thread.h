/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 17:03:10 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/09/24 21:35:46 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_THREAD_H
# define PHILO_THREAD_H

# include "philo.h"

typedef struct s_philo	t_philo;

void	*philo_thread_wrapper(void *data);
void	*philo_thread(void *data);
bool	is_simulation_over(t_philo *philo, struct timeval *begin);
void	philo_log(unsigned int id, struct timeval *begin, void (*printfun)(void));
void	eat(void);
void	fall_asleep(void);
void	take_fork(void);
void	think(void);
void	die(void);

#endif
