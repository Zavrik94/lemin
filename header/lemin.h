/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azavrazh <azavrazh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 19:20:57 by azavrazh          #+#    #+#             */
/*   Updated: 2018/10/28 19:20:57 by azavrazh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "../ft_printf/includes/ft_printf.h"
# include <stdio.h>

typedef struct		s_con
{
	char			*name;
	struct s_con	*next;
	struct s_con	*prev;
}					t_con;

typedef struct		s_room
{
	char			*name;
	int				x;
	int				y;
	int				path;
	int				ant;
	int				curant;
	int				onway;
	struct s_room	**conn;
	struct s_room	*next;
	struct s_room	*prev;
}					t_room;

typedef	struct		s_lflags
{
	unsigned int	steps : 1;
	unsigned int	silent : 1;
	unsigned int	solo : 1;
	unsigned int	ways : 1;
	unsigned int	help : 1;
	unsigned int	is_start : 1;
	unsigned int	is_end : 1;
	unsigned int	start_end : 1;

}					t_fl;

typedef	struct		s_lines
{
	char			*str;
	struct s_lines	*prev;
	struct s_lines	*next;

}					t_ln;

typedef struct		s_lemin
{
	int				antcnt;
	int				numofways;
	t_room			*room;
	t_room			*rhead;
	t_con			*conn;
	t_con			*chead;
	t_room			*start;
	t_room			*end;
	int				cntendant;
	t_fl			flags;
	t_ln			*output;
	t_ln			*output_start;

}					t_lemin;

t_lemin				g_ants;
extern const char	*g_usage;

void				ft_read(int fd);
void				pars_con();
t_con				*headofcon(t_con *list);
t_room				*headofroom(t_room *list);
void				path(t_room *start, t_room *end);
void				move();
t_room				*findbestway(t_room *room);
void				ways();
void				check_con(const char *str);
t_room				*findroombyname(char *name);
void				check_room(const char *str);
void				ft_error(char *err);
int					check_coord(int	x, int y, char *name);
t_room				*findroombycon(char *name, t_con *con, t_room *head);
int					havethisconn(char *roomname, t_con *conn);
void				delaftersplit(char ***arr);
void				print_map();
int					iterate_flags(int ac, const char **av);
bool				parse_flags(const char *str);
bool				parse_flags2(const char *str);
int					findbestways();
void				printways();
int					countconnroom(char *name, t_con *head);
t_room				*findprevonway(t_room *room, int num);

#endif
