/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exceptions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 21:56:49 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/09/24 21:44:46 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>
#include <unistd.h>

int	except_invalid_arguments(const char *exec_name)
{
	write(2, "Usage: ", 7);
	write(2, exec_name, ft_strlen(exec_name));
	write(2, " number_of_philosophers time_to_die time_to_eat"
		"time_to_sleep [number_of_times_each_philosopher_must_eat]\n", 105);
	return (-1);
}

int	except_no_memory(void)
{
	write(2, "Error: out of memory\n", 21);
	return (-1);
}

int	except_thread_fail(void)
{
	write(2, "Error: failed to initialize a thread\n", 37);
	return (-1);
}
