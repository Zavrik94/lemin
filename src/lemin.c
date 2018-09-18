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
	ft_read(fd);
	system("leaks a.out");
	return (0);
}