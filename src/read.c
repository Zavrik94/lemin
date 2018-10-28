/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azavrazh <azavrazh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 19:13:04 by azavrazh          #+#    #+#             */
/*   Updated: 2018/10/28 19:50:32 by azavrazh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

void	init_deinit(bool indeinit)
{
	if (indeinit)
	{
		g_ants.conn = (t_con*)ft_memalloc(sizeof(t_con));
		g_ants.chead = g_ants.conn;
		g_ants.room = (t_room*)ft_memalloc(sizeof(t_room));
		g_ants.rhead = g_ants.room;
		g_ants.output_start =
		g_ants.output = (t_ln*)ft_memalloc(sizeof(t_ln));
	}
	else
	{
		if (g_ants.antcnt < 1)
			ft_error("Error to read ants");
		if (g_ants.start == NULL || g_ants.end == NULL)
			ft_error("Don`t have start or end");
		g_ants.room = g_ants.room->prev;
		if (g_ants.room->next)
			free(g_ants.room->next);
		g_ants.room->next = NULL;
		g_ants.conn = g_ants.conn->prev;
		if (g_ants.conn == NULL)
			ft_error("No connections");
		free(g_ants.conn->next);
		g_ants.conn->next = NULL;
	}
}

void	read_room(const char *line)
{
	char	**room;
	t_room	*temp;

	check_room(line);
	room = ft_strsplit(line, ' ');
	g_ants.room->name = ft_strdup(room[0]);
	g_ants.room->x = ft_atoi(room[1]);
	g_ants.room->y = ft_atoi(room[2]);
	g_ants.room->next = NULL;
	if (check_coord(g_ants.room->x, g_ants.room->y, g_ants.room->name))
	{
		delaftersplit(&room);
		ft_error("room with same coord");
	}
	if (g_ants.flags.is_start && !(g_ants.flags.is_start = false))
		(g_ants.start = g_ants.room);
	if (g_ants.flags.is_end && !(g_ants.flags.is_end = false))
		(g_ants.end = g_ants.room);
	temp = g_ants.room;
	g_ants.room->next = (t_room*)malloc(sizeof(t_room));
	g_ants.room = g_ants.room->next;
	g_ants.room->prev = temp;
	g_ants.room->next = NULL;
	delaftersplit(&room);
}

void	read_conn(const char *line)
{
	t_con	*tmp;

	check_con(line);
	g_ants.conn->name = ft_strdup(line);
	g_ants.conn->next = (t_con*)malloc(sizeof(t_con));
	tmp = g_ants.conn;
	g_ants.conn = g_ants.conn->next;
	g_ants.conn->prev = tmp;
}

bool	add_node_to_output(const char *line)
{
	g_ants.output->str = (char *)line;
	g_ants.output->next = (t_ln*)ft_memalloc(sizeof(t_ln));
	g_ants.output->next->prev = g_ants.output;
	g_ants.output = g_ants.output->next;
	return (true);
}

void	ft_read(int fd)
{
	char	*l;
	int		cnt;

	cnt = 0;
	g_ants.antcnt = -1;
	init_deinit(true);
	while (get_next_line(fd, &l) > 0 && l[0])
	{
		add_node_to_output(l);
		if (parse_flags2(l))
			continue ;
		else if (cnt == 0 && ft_isnum(l))
			(g_ants.antcnt = ft_atoi(l)) && ++cnt;
		else if (g_ants.antcnt <= 0)
			ft_error("Error to read ants");
		else if (ft_isalnum(l[0]) && ft_strstr(l, "-") && ft_strstr(l, " "))
			ft_error("Error input format");
		else if (ft_isalnum(l[0]) && ft_strstr(l, " "))
			read_room(l);
		else if (ft_isalnum(l[0]) && ft_strstr(l, "-"))
			read_conn(l);
	}
	if (cnt == 0)
		ft_error("file empty");
	init_deinit(false);
}
