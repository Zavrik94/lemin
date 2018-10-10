#include <lemin.h>

void	conn_init(void)
{
	g_ants.conn = (t_con*)malloc(sizeof(t_con));
	g_ants.conn->prev = NULL;
	g_ants.chead = g_ants.conn;
}

void	room_init(void)
{
	g_ants.room = (t_room*)malloc(sizeof(t_room));
	g_ants.room->prev = NULL;
	g_ants.rhead = g_ants.room;
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
	g_ants.room->next = (t_room*)malloc(sizeof(t_room));
	g_ants.room = g_ants.room->next;
	g_ants.room->prev = temp;
}

void	read_conn(char *line)
{
	t_con	*tmp;

	g_ants.conn->name = ft_strdup(line);
	tmp = g_ants.conn;
	g_ants.conn->next = (t_con*)malloc(sizeof(t_con));
	g_ants.conn = g_ants.conn->next;
	g_ants.conn->prev = tmp;
}

void	ft_read(int fd)
{
	char	*line;

	room_init();
	conn_init();
	while(get_next_line(fd, &line) > 0)
	{
		if (ft_isnum(line) && !(ft_strstr(line, " ")) && !(ft_strstr(line, "-")))
			g_ants.antcnt = ft_atoi(line);
		else if (ft_isalnum(line[0]) && !(ft_strstr(line, "-")) && ft_strstr(line, " "))
			read_room(line);
		else if (ft_isalnum(line[0]) && ft_strstr(line, "-") && !(ft_strstr(line, " ")))
			read_conn(line);
		else if (ft_strstr(line, "##start"))
        {
            ft_strdel(&line);
            get_next_line(fd, &line);
            read_room(line);
            g_ants.start = g_ants.room->prev;
        }
        else if (ft_strstr(line, "##end"))
        {
            ft_strdel(&line);
            get_next_line(fd, &line);
            read_room(line);
            g_ants.end = g_ants.room->prev;
        }
		ft_strdel(&line);
	}
	g_ants.room = g_ants.room->prev;
	free(g_ants.room->next);
	g_ants.room->next = NULL;
	g_ants.conn = g_ants.conn->prev;
	free(g_ants.conn->next);
	g_ants.conn->next = NULL;
}
