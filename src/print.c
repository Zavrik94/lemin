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
