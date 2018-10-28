#include <lemin.h>

void	print_map()
{
	while (g_ants.output_start)
	{
		if (g_ants.output_start->str)
			ft_printf("%s\n", g_ants.output_start->str);
		g_ants.output_start = g_ants.output_start->next;
	}
	ft_putchar('\n');
}

t_room	*findnextbyway(t_room *room, int way)
{
	int 	i = -1;
	int 	min = 0;
	int 	res;

	while (room->conn[++i])
	{
		if (g_ants.flags.start_end && room != g_ants.start)
			if (room->conn[i] == g_ants.end)
				return (room->conn[i]);
		if (!g_ants.flags.start_end)
			if (room->conn[i] == g_ants.end)
				return (room->conn[i]);
		if (min == 0 && room->conn[i]->onway == way && room->conn[i] != g_ants.start)
		{
			res = i;
			min = room->path;
		}
		else if (room->conn[i]->path < min && room->conn[i]->onway == way)
		{
			res = i;
			min = room->path;
		}
	}
	return (room->conn[res]);
}

void	printways()
{
	t_room	*start;
	int 	i = 0;

	while (++i <= g_ants.numofways)
	{
		start = g_ants.start;
		ft_printf("[%s]", start->name);
		while (start != g_ants.end && start->path != -1)
		{
			start = findnextbyway(start, i);
			ft_printf("->[%s]", start->name);
		}
		ft_printf("\n");
	}
	ft_printf("\n");
}
