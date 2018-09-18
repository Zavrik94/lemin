#include <lemin.h>

void	read_room(char *line)
{
	int		i;
	int		namelen;

	i = -1;
	namelen = 0;
	while (line[++i] != ' ')
		namelen++;
	g_ants.room = (t_room)malloc(sizeof(t_room))
}

void	ft_read(int fd)
{
	char	*line;

	while(get_next_line(fd, &line) > 0)
	{
		if (ft_isalnum(line[0]) && !(ft_strstr(line, " ")) && !(ft_strstr(line, "-")))
			g_ants.antcnt = ft_atoi(line);
		if (ft_isalnum(line[0]) && !(ft_strstr(line, "-")) && ft_strstr(line, " "))
			read_room(line);
		ft_strdel(&line);
	}
	//ft_printf("%s\n", g_ants.room.name);
}