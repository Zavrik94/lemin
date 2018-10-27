
#include <lemin.h>

int			iterate_flags(int ac, const char **av)
{
	int		fd;
	int 	i;

	i = 0;
	while (++i < ac && ft_strstr("-", av[i]))
	{
		if (parse_flags(av[i]) == false)
			break ;
	}
	if (i > ac - 1)
		return (0);
	if (!(fd = open(av[i], O_RDONLY)))
		return (-1);
	return (fd);
}

bool	parse_flags(const char *str)
{
	if (ft_strequ(str, "--silent"))
		return (g_ants.flags.silent = true);
	else if (ft_strequ(str, "--solo"))
		return (g_ants.flags.solo = true);
	else if (ft_strequ(str, "--ways"))
		return (g_ants.flags.ways = true);
	else if (ft_strequ(str, "--steps"))
		return (g_ants.flags.steps = true);
	else if (ft_strequ(str, "--help"))
		return (g_ants.flags.help = true);
	return (false);
}

bool	parse_flags2(const char *str)
{
	if (ft_strequ(str, "##silent"))
		return (g_ants.flags.silent = true);
	else if (ft_strequ(str, "##solo"))
		return (g_ants.flags.solo = true);
	else if (ft_strequ(str, "##ways"))
		return (g_ants.flags.ways = true);
	else if (ft_strequ(str, "##steps"))
		return (g_ants.flags.steps = true);
	else if (ft_strequ(str, "##help"))
		return (g_ants.flags.help = true);
	else if (ft_strequ(str, "##start"))
		return (g_ants.flags.is_start = true);
	else if (ft_strequ(str, "##end"))
		return (g_ants.flags.is_end = true);
	else if (str[0] == '#')
		return (true);
	return (false);
}
