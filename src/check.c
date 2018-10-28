/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azavrazh <azavrazh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 16:09:29 by azavrazh          #+#    #+#             */
/*   Updated: 2018/10/28 19:53:33 by azavrazh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

int		havesameroom(char *name)
{
	t_room *room;

	room = headofroom(g_ants.room);
	while (room)
	{
		if (room->next == NULL)
			break ;
		if (ft_strequ(room->name, name))
			return (1);
		room = room->next;
	}
	return (0);
}

void	check_room(const char *str)
{
	int		i;
	int		spc;
	char	**chk;

	i = -1;
	spc = 0;
	while (str[++i])
		if (str[i] == ' ')
			spc++;
	if (spc != 2)
		ft_error("Room has bad format!");
	chk = ft_strsplit(str, ' ');
	i = 0;
	while (chk[i])
		i++;
	if (i != 3 || (!ft_isnum(chk[1]) || !ft_isnum(chk[2]))
		|| (chk[0][0] == 'L' || chk[0][0] == '#'))
		ft_error("Room has bad format!");
	i = -1;
	while (chk[0][++i])
		if (chk[0][i] == ' ' || chk[0][i] == '\t' || chk[0][i] == '-')
			ft_error("Room has bad format!");
	if (havesameroom(chk[0]))
		ft_error("Duplicate room");
	delaftersplit(&chk);
}

void	check_con(const char *str)
{
	int		i;
	int		t;
	char	*name1;
	char	*name2;

	i = -1;
	t = 0;
	while (str[++i])
		if (str[i] == '-')
			t++;
		else if (str[i] == ' ' || str[i] == '\t')
			ft_error("wrong connection format");
	if (t != 1)
		ft_error("wrong connection format");
	i = -1;
	while (str[++i])
		if (str[i] == '-')
			break ;
	name1 = ft_strncpy(str, i);
	name2 = ft_strscpy(str, ++i);
	if (!findroombyname(name2) || !findroombyname(name1))
		ft_error("connection with unknown room");
	ft_strdel(&name1);
	ft_strdel(&name2);
}

int		check_coord(int x, int y, char *name)
{
	t_room *head;

	head = headofroom(g_ants.room);
	while (head)
	{
		if (x == head->x && y == head->y && ft_strcmp(name, head->name))
			return (1);
		head = head->next;
	}
	return (0);
}

int		havethisconn(char *roomname, t_con *conn)
{
	t_room	*room;
	int		i;

	room = findroombyname(roomname);
	if (room->conn == NULL)
		return (0);
	i = -1;
	while (room->conn[++i])
		if (room->conn[i] ==
			findroombycon(room->name, conn, headofroom(g_ants.room)))
			return (1);
	return (0);
}
