/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azavrazh <azavrazh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 18:57:17 by azavrazh          #+#    #+#             */
/*   Updated: 2018/10/28 18:57:17 by azavrazh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

int		checkzeropath(void)
{
	t_room	*head;

	head = headofroom(g_ants.room);
	while (head)
	{
		if (head->path == 0 && head != g_ants.start)
			return (1);
		head = head->next;
	}
	return (0);
}

int		haveway(void)
{
	t_room	*head;
	int		i;

	head = headofroom(g_ants.rhead);
	while (head)
	{
		i = -1;
		if (head->path == 0)
			while (head->conn[++i])
				if (head->conn[i]->path != 0)
					return (1);
		head = head->next;
	}
	return (0);
}

void	pathofpath(t_room *start, t_room *head)
{
	int		i;

	if (countconnroom(head->name, headofcon(g_ants.conn)) == 1
		&& head != g_ants.start && head != g_ants.end && head->conn[0])
		head->conn[0]->path = -1;
	else if (head->path != 0 && (i = -1) < 0)
		while (head->conn[++i])
		{
			if (head->conn[i]->path == 0
				&& head->conn[i] != start && head->path == -1)
				head->conn[i]->path = -1;
			else if (head->conn[i]->path == 0 && head->conn[i] != start)
				head->conn[i]->path = head->path + 1;
		}
}

void	path(t_room *start, t_room *end)
{
	t_room	*head;
	int		i;
	int		max;

	end->path = 1;
	while (checkzeropath() && (head = headofroom(g_ants.room)))
	{
		while (head)
		{
			pathofpath(start, head);
			head = head->next;
		}
		if (!haveway())
			ft_error("Has no way");
	}
	i = -1;
	max = 0;
	while (g_ants.start->conn[++i])
		if (g_ants.start->conn[i]->path > max)
			g_ants.start->path = max + 1;
}
