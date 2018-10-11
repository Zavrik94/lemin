#include <lemin.h>

int		main(int ac, char **av)
{
	int		fd;

	if (ac > 2)
		return (0);
	else if (ac < 2)
		fd = 0;
	else
		fd = open(av[1], O_RDONLY);
	if (fd < 0)
	    return (0);
	ft_read(fd);
	pars_con();
	path(g_ants.start, g_ants.end);
	move();
	//system("leaks a.out");
	return (0);
}