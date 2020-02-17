/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karmand <karmand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 16:08:11 by karmand           #+#    #+#             */
/*   Updated: 2020/01/29 16:22:11 by karmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

char	get_int(int fd, int *n)
{
	char	c;
	int		r;
	int		sign;

	*n = 0;
	sign  = 1;
	r = read(fd, &c, 1);
	while (r && ft_iswp(c))
		r = read(fd, &c, 1);
	if (c == '-')
	{
		sign = -1	;
		r = read(fd, &c, 1);
	}
	while (r && ft_isdigit(c))
	{
		(*n) = 10 * (*n) + (c - '0');
		r = read(fd, &c, 1);
	}
	return (sign * c);
}

char	get_double(int fd, double *d)
{
	int n;
	int r;
	char c;
	int sign;

	n = 0;
	c = get_int(fd, &n);
	(*d) = (double)n;
	if (c != '.')
		return (c);
	sign = ((n < 0) ? -1 : 0 );
	n = 10;
	r = read(fd, &c, 1);
	while (r && ft_isdigit(c))
	{
		(*d) += sign * ((double)(c - '0'))/(double)n;
		n *= 10;
		r = read(fd, &c, 1);
	}
	return (c);
}
