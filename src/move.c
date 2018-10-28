/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azavrazh <azavrazh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 18:50:43 by azavrazh          #+#    #+#             */
/*   Updated: 2018/10/28 18:50:43 by azavrazh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

t_room	*findprevonway(t_room *room, int num)
{
	int		i;
	int		max;
	t_room	*temp;

	i = -1;
	max = 0;
	while (room->conn[++i])
	{
		if (room->conn[i] == g_ants.start)
			return (room->conn[i]);
		if (room->conn[i]->onway == num)
		{
			if (max == 0)
			{
				temp = room->conn[i];
				max = room->conn[i]->path;
			}
			else if (room->conn[i]->path > max)
			{
				temp = room->conn[i];
				max = room->conn[i]->path;
			}
		}
	}
	return (temp);
}

int		mcpath(int num)
{
	t_room	*start;
	int		i;
	int		min;

	i = -1;
	if (num == 0)
	{
		start = g_ants.start;
		min = 0;
		while (start->conn[++i])
			if (min == 0 && start->conn[i]->path > 0)
				min = start->conn[i]->path;
			else if (min != 0 && start->conn[i]->path < min
				&& start->conn[i]->path > 0)
				min = start->conn[i]->path;
		return (min);
	}
	else
	{
		start = g_ants.start;
		while (start->conn[++i])
			if (start->conn[i]->onway == num)
				break ;
		return (start->conn[i]->path);
	}
}

void	pathmoveonway(t_room *prev, t_room *end, int numofsteps, int num)
{
	int		k;

	if (prev->ant > 0)
	{
		if (end == g_ants.end)
			g_ants.cntendant++;
		end->ant = prev->ant;
		if (prev == g_ants.start)
		{
			k = mcpath(num) / mcpath(0);
			if (((numofsteps + (k - 1)) % k == 0) && (mcpath(num)
				< (g_ants.antcnt - prev->ant) || mcpath(num) == mcpath(0)))
			{
				prev->ant++;
				if (prev->ant > g_ants.antcnt)
					prev->ant = 0;
			}
			else
				end->ant = 0;
		}
		else
			prev->ant = 0;
		if (end->ant != 0)
			ft_printf("L%d-%s ", end->ant, end->name);
	}
}

void	moveonway(int num, int numofsteps)
{
	t_room	*end;
	t_room	*prev;

	end = g_ants.end;
	while (end != g_ants.start)
	{
		prev = findprevonway(end, num);
		pathmoveonway(prev, end, numofsteps, num);
		end = prev;
	}
}

void	move(void)
{
	int		i;
	int		numofsteps;

	g_ants.start->ant = 1;
	numofsteps = 1;
	g_ants.cntendant = 0;
	while (g_ants.cntendant < g_ants.antcnt)
	{
		if (g_ants.flags.start_end)
		{
			while (g_ants.cntendant < g_ants.antcnt)
				moveonway(findbestways(), numofsteps);
			ft_printf("\n");
			break ;
		}
		if (g_ants.flags.solo)
			moveonway(findbestways(), numofsteps);
		else if ((i = 1) > 0)
			while (i <= g_ants.numofways)
				moveonway(i++, numofsteps);
		ft_printf("\n");
		numofsteps++;
	}
	if (g_ants.flags.steps)
		ft_printf("steps : %d\n", numofsteps);
}
