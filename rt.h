/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karmand <karmand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 13:22:08 by karmand           #+#    #+#             */
/*   Updated: 2020/01/29 15:59:23 by karmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define SUCCESS			0
# define ERROR_OPEN			-1
# define ERROR_ARGUMENT		-2
# define ERROR_MALLOC		-3
# define ERROR_PARS_COLOR	-4
# define ERROR_PARS_POINT	-5
# define ERROR_PARS_		-6
# define ERROR_DEF_RES		-7
# define ERROR_CAM_MISS		-8
# define ERROR_FOV			-10
# define ERROR_             -11


typedef struct		s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char 	b;
}					t_color;

typedef struct		s_point
{
	double			x;
	double			y;
	double			z;
}					t_point;

typedef struct		s_vector
{
	double			x;
	double			y;
	double			z;
}					t_vector;

/*
**	Liste des objet
*/

typedef struct		s_sp
{
	t_point			centre;
	t_color			color;
	int				rayon;
}					t_sp;

typedef struct		s_pl
{
	t_point			point;
	t_vector		norm;
	t_color			color;
}					t_pl;

typedef struct		s_cy
{
	t_point			point;
	t_vector		norm;
	int 			rayon;
	int				height;
	t_color			color;
}					t_cy;

typedef struct		s_tr
{
	t_point			p1;
	t_point			p2;
	t_point			p3;
	t_color			color;
}					t_tr;

typedef struct		s_cam
{	
	t_point			point;
	t_vector		dir;
	int				fov;
}					t_cam;

typedef struct		s_light
{
	t_point			point;
	int				brightness;
	t_color			color;
}					t_light;

/*
**	fin des list objet
*/

typedef struct		s_lobj
{
	void			*obj;
	struct s_lobj	*next;
}					t_lobj;

typedef struct		s_para
{
	int				res_width;
	int				res_height;
	double			brightness;
	t_color			color;
}					t_para;

typedef struct		s_data
{
	t_para			para;
	t_lobj			*lobj;
	t_lobj			*llight;
	t_lobj			*lcam;
}					t_data;

//sructure pour intersection.

int					dest_data(t_data *data);
int					parsing(int fd, t_data *data);
int 				error(int code);

//fonction de lib

int					ft_strcmp(char *s1, char *s2);
int					ft_isdigit(char c);
int					ft_iswp(char c);

/*
**	Fonction de parsing
*/

int		parsing(int fd, t_data *data);
char	get_int(int fd, int *n);
char	get_double(int fd, double *d);
char    get_name(int fd, char *name);

/*
**	Fonction de buffer
*/

t_buffer	*buf_create(int size);
void		buf_dest(t_buffer *b);
int			buf_addchar(t_buffer *b, char c);
char		*buf_to_string(t_buffer *b);

#endif
