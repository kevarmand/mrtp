/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karmand <karmand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 13:27:41 by karmand           #+#    #+#             */
/*   Updated: 2020/01/29 16:22:05 by karmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

//retour du pqrsong => nombre d'element dans ma liste pour cree la liste.
//indexer
// Erreur de parsing 
/* -1 => imposible d ouvrir le fichier
*/

int		pars_color(int fd, t_color *color)
{
	int		n;
	int		c;

	c = get_int(fd, &n);
	if (c != ',' || n > 255)
		return (ERROR_PARS_COLOR);
	color->r = n;
	c = get_int(fd, &n);
	if (c != ',' || n > 255)
		return (ERROR_PARS_COLOR);
	color->g = n;
	c = get_int(fd, &n);
	if (ft_iswp(c) != 1 || n > 255)
		return (ERROR_PARS_COLOR);
	color->b = n;	
	return (SUCCESS);
}

int		pars_point(int fd, t_point *point)
{
	double	d;
	char	c;

	c = get_int(fd, &d);
	if (c != ',')
		return (ERROR_PARS_POINT);
	color->r = n;
	c = get_int(fd, &d);
	if (c != ',')
		return (ERROR_PARS_POINT);
	color->g = n;
	c = get_int(fd, &d);
	if (ft_iswp(c) != 1)
		return (ERROR_PARS_POINT);
	color->b = n;
	return (SUCCESS);
}

int		pars_check(int fd, char c, int *ret)
{
	r = read(fd, &c, 1);
	while (r && ft_iswp(c))
		r = read(fd, &c, 1);

	if (c[0] != '.')
		return (c);

	
}

int		parsing(int fd, t_data *data)
{	
	int		err;
	int		r;
	char	c;
	int		ret;

	r = read(fd, &c, 1);
	while (r)
	{
		while (r && c == '\n')
			r = read(fd, &c, 1);
		if ((err = pars_check(fd, c, &ret)))
			return (err);
		if ((err = pars_switch(fd, data, ret)))
			return (err);
		r = read(fd, &c, 1);
	}
	return (SUCCESS);
}
