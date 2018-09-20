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

typedef struct		s_con
{
	char 			*name;
	struct s_con	*next;
	struct s_con	*prev;
}					t_con;

typedef struct		s_room
{
	char			*name;
	t_coo			coord;
	struct s_room	**conn;
	struct s_room	*next;
	struct s_room	*prev;
}					t_room;


typedef struct		s_lemin
{
	int				antcnt;
	t_room			*room;
	t_room          *rhead;
	t_con        	*conn;
	t_con			*chead;
}					t_lemin;


t_lemin g_ants;

void				ft_read(int fd);
void				*freelastconn(t_files *head);
t_files     		*findinconn(t_files *head, char *str);
void                pars_con();

#endif