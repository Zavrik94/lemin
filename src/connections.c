/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azavrazh <azavrazh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 16:26:58 by azavrazh          #+#    #+#             */
/*   Updated: 2018/10/28 21:28:21 by azavrazh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

int		countconnroom(char *name, t_con *head)
{
	int		res;

	res = 0;
	while (head)
	{
		if (ft_strstr(head->name, name))
			res++;
		head = head->next;
	}
	return (res);
}

t_room	*findroombycon(char *name, t_con *con, t_room *head)
{
	char	*name2;
	char	**temp;

	temp = ft_strsplit(con->name, '-');
	if ((!ft_strequ(temp[0], name) && !ft_strequ(temp[1], name))
	|| ft_strequ(temp[1], temp[0]))
	{
		delaftersplit(&temp);
		return (NULL);
	}
	if (ft_strequ(temp[0], name))
		name2 = temp[1];
	if (ft_strequ(temp[1], name))
		name2 = temp[0];
	while (head)
	{
		if (ft_strcmp(head->name, name2) == 0)
			break ;
		head = head->next;
	}
	delaftersplit(&temp);
	return (head);
}

void	partofadd(t_con *head, char *name, int con)
{
	int		i;

	i = -1;
	while (head)
	{
		if (ft_strstr(head->name, name) && havethisconn(name, head))
			con--;
		else if (ft_strstr(head->name, name) && !havethisconn(name, head))
		{
			g_ants.rhead->conn[++i] =
					findroombycon(name, head, headofroom(g_ants.rhead));
			if (!g_ants.rhead->conn[i])
				i--;
			if (g_ants.rhead == g_ants.start
				&& g_ants.rhead->conn[i] == g_ants.end)
				g_ants.flags.start_end = true;
		}
		head = head->next;
	}
	g_ants.rhead->conn[con] = NULL;
}

void	addcontorom(char *name, t_con *head)
{
	int		con;

	while (g_ants.rhead)
	{
		if (!ft_strcmp(g_ants.rhead->name, name))
			break ;
		g_ants.rhead = g_ants.rhead->next;
	}
	if (!g_ants.rhead)
		return ;
	con = countconnroom(g_ants.rhead->name, g_ants.chead);
	if (con == 0)
		ft_error("Room with no connections");
	g_ants.rhead->conn = (t_room**)malloc(sizeof(t_room*) * (con + 1));
	g_ants.rhead->conn[0] = NULL;
	partofadd(head, name, con);
	g_ants.rhead = headofroom(g_ants.rhead);
}

void	pars_con(void)
{
	g_ants.room = headofroom(g_ants.room);
	while (g_ants.room)
	{
		addcontorom(g_ants.room->name, g_ants.chead);
		g_ants.room->curant = 0;
		g_ants.room->path = 0;
		g_ants.room->ant = 0;
		g_ants.room->onway = 0;
		g_ants.chead = headofcon(g_ants.chead);
		if (!g_ants.room->next)
			break ;
		g_ants.room = g_ants.room->next;
	}
}
