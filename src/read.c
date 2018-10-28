#include <lemin.h>

void	init_deinit(bool indeinit, int cnt)
{
	if (indeinit)
	{
		//ft_bzero(&g_ants, sizeof(t_lemin));
		g_ants.conn = (t_con*)ft_memalloc(sizeof(t_con));
		g_ants.chead = g_ants.conn;
		g_ants.room = (t_room*)ft_memalloc(sizeof(t_room));
		g_ants.rhead = g_ants.room;
		g_ants.output_start =
		g_ants.output = (t_ln*)ft_memalloc(sizeof(t_ln));
	}
	else
	{
		if (cnt == 0)
			ft_error("file empty");
		if (g_ants.antcnt < 1)
			ft_error("Error to read ants");
		if (g_ants.start == NULL || g_ants.end == NULL)
			ft_error("Don`t have start or end");
		g_ants.room = g_ants.room->prev;
		if (g_ants.room->next)
			free(g_ants.room->next);
		g_ants.room->next = NULL;
		g_ants.conn = g_ants.conn->prev;
		if (g_ants.conn == NULL)
			ft_error("No connections");
		g_ants.conn->next = NULL;
	}
}

void	read_room(const char *line)
{
	char	**room;
	t_room	*temp;

	if (!check_room(line))
		ft_error("Room has bad format!");
	room = ft_strsplit(line, ' ');
	g_ants.room->name = ft_strdup(room[0]);
	g_ants.room->x = ft_atoi(room[1]);
	g_ants.room->y = ft_atoi(room[2]);
	g_ants.room->next = NULL;
	if (check_coord(g_ants.room->x, g_ants.room->y, g_ants.room->name))
	{
		delaftersplit(&room);
		ft_error("room with same coord");
	}
	if (g_ants.flags.is_start)
		(g_ants.start = g_ants.room) && (g_ants.flags.is_start = false);
	if (g_ants.flags.is_end)
		(g_ants.end = g_ants.room) && (g_ants.flags.is_end = false);
	temp = g_ants.room;
	g_ants.room->next = (t_room*)malloc(sizeof(t_room));
	g_ants.room = g_ants.room->next;
	g_ants.room->prev = temp;
	delaftersplit(&room);
}

void	read_conn(const char *line)
{
	t_con	*tmp;

	check_con(line);
	g_ants.conn->name = ft_strdup(line);
	tmp = g_ants.conn;
	g_ants.conn->next = (t_con*)malloc(sizeof(t_con));
	g_ants.conn = g_ants.conn->next;
	g_ants.conn->prev = tmp;
}

bool	add_node_to_output(const char *line)
{
	g_ants.output->str = (char *)line;
	g_ants.output->next = (t_ln*)ft_memalloc(sizeof(t_ln));
	g_ants.output->next->prev = g_ants.output;
	g_ants.output = g_ants.output->next;
	return (true);
}

void	ft_read(int fd)
{
	char	*line;
	int 	cnt;

	cnt = 0;
	g_ants.antcnt = -1;
	init_deinit(true, cnt);

	while(get_next_line(fd, &line) > 0 && line[0])
	{
		add_node_to_output(line);
		if (parse_flags2(line))
			continue ;
		else if (cnt == 0 && ft_isnum(line))
			(g_ants.antcnt = ft_atoi(line)) && ++cnt;
		else if (g_ants.antcnt <= 0)
			ft_error("Error to read ants");
		else if (ft_isalnum(line[0]) && ft_strstr(line, "-") && ft_strstr(line, " "))
			ft_error("Error input format");
		else if (ft_isalnum(line[0]) && ft_strstr(line, " "))
			read_room(line);
		else if (ft_isalnum(line[0]) && ft_strstr(line, "-"))
			read_conn(line);
	}
	init_deinit(false, cnt);
}
