/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 21:59:57 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/09/24 21:49:17 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stddef.h>
# include <stdbool.h>

size_t			ft_strlen(const char *s);
bool			ft_strisdigit(const char *s);
long			ft_atol(const char *s);
int				ft_print_unsigned(unsigned int n);
size_t			ft_strlen(const char *s);
bool			ft_isspace(int c);

#endif
