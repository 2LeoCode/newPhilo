/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exceptions.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 22:00:29 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/09/24 21:44:15 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCEPTIONS_H
# define EXCEPTIONS_H

int	except_invalid_arguments(const char *exec_name);
int	except_no_memory(void);
int	except_thread_fail(void);

#endif
