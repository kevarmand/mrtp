/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karmand <karmand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 13:59:23 by karmand           #+#    #+#             */
/*   Updated: 2020/01/11 17:34:21 by karmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int	test_param(int ac, char **av)
{
	if (ac < 2 && ac > 3)
		return (ERROR_ARGUMENT);
	if (ac == 3 && 0 != ft_strcmp(av[2], "-save"))
		return (ERROR_ARGUMENT);
	return (SUCCESS);
}

static int	open_file(int *fd, char *name)
{
	*fd = open(name, O_RDONLY);
	if (*fd == -1)
		return (ERROR_OPEN);	
	return (SUCCESS);
}

int main(int ac, char **av)
{
	int err;
	int fd;
	t_data data;

	if ((err = test_param(ac, av)))
		return (error(err));
	if ((err = open_file(&fd, av[1])))
		return (error(err));
	//if ((err = init_data(&data)))
	//	return (error(err));
	if ((err = parsing(fd, &data)))
		return (error(err));	// penser a detruire la data en ca derreur
	//test de la sauvegarde

	//lancement du rt
	return (0);
}
