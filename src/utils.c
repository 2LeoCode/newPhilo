/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 21:58:06 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/09/24 22:12:36 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <unistd.h>

static __always_inline bool	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static __always_inline bool ft_isspace(int c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

size_t	ft_strlen(const char *s)
{
	const char	*ptr = s;

	while (*ptr)
		++ptr;
	return ((uintptr_t)ptr - (uintptr_t)s);
}

bool	ft_strisdigit(const char *s)
{
	while (ft_isspace(*s))
		++s;
	while (ft_isdigit(*s))
		++s;
	while (ft_isspace(*s))
		++s;
	return (!*s);
}

long	ft_atol(const char *s)
{
	long	n;

	n = 0;
	while (ft_isspace(*s))
		++s;
	while (ft_isdigit(*s))
		n = 10 * n + (*s++ - '0');
	return (n);
}

int		ft_print_unsigned(unsigned int n)
{
	if (n < 10)
		return (write(1, (unsigned char[1]){n + '0'}, 1));
	return (ft_print_unsigned(n / 10U) + ft_print_unsigned(n % 10U));
}
