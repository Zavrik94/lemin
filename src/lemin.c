#include <lemin.h>

int		main(int ac, const char **av)
{
	const int		fd = iterate_flags(ac, av);

	if (fd == -1)
		ft_error("Can not open file");
	ft_read(fd);
	print_map();
	pars_con();
	path(g_ants.start, g_ants.end);
	ways();
    move();
	return (0);
}