#include <lemin.h>

void	room_init(void)
{
	g_ants.room = (t_room*)malloc(sizeof(t_room));
	g_ants.room->prev = NULL;
}

void	read_room(char *line)
{
	int		i;
	int		namelen;
	t_room	*temp;

	i = -1;
	namelen = 0;
	while (line[++i] != ' ')
		namelen++;
	g_ants.room->name = (char*)malloc(sizeof(char) * namelen);
	g_ants.room->name[namelen] = '\0';
	i = -1;
	while (line[++i] != ' ')
		g_ants.room->name[i] = line[i];
	temp = g_ants.room;
	ft_printf("%s\n", g_ants.room->name);
	g_ants.room->next = (t_room*)malloc(sizeof(t_room));
	g_ants.room = g_ants.room->next;
	g_ants.room->prev = temp;
}

void	ft_read(int fd)
{
	char	*line;

	room_init();
	while(get_next_line(fd, &line) > 0)
	{
		if (ft_isnum(line) && !(ft_strstr(line, " ")) && !(ft_strstr(line, "-")))
			g_ants.antcnt = ft_atoi(line);
		else if (ft_isalnum(line[0]) && !(ft_strstr(line, "-")) && ft_strstr(line, " "))
			read_room(line);
		else if (ft_isalnum(line[0]) && ft_strstr(line, "-") && !(ft_strstr(line, " ")))
			read_conn(line);
		ft_strdel(&line);
	}
	g_ants.room = g_ants.room->prev;
	free(g_ants.room->next);
	g_ants.room->next = NULL;
}