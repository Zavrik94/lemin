/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azavrazh <azavrazh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 18:18:37 by azavrazh          #+#    #+#             */
/*   Updated: 2018/09/18 19:20:20 by azavrazh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN
#define LEM_IN

#include "../ft_printf/includes/ft_printf.h"

typedef struct		s_coo
{
	int				x;
	int				y;
}					t_coo;

typedef struct				s_room
{
	char			*name;
	t_coo			coord;
	int				*conn;
	struct s_room	*next;
}					t_room;


typedef struct		s_lemin
{
	int				antcnt;
	t_room			room;
}					t_lemin;


t_lemin				g_ants;

void				ft_read(int fd);

#endif