#include <lemin.h>

int     countconnroom(char  *name, t_con *head)
{
    int     res;

    res = 0;
    while(head)
    {
        if (ft_strstr(head->name, name))
            res++;
        head = head->next;
    }
    return (res);
}

t_room	*findroombycon(char* name, t_con *con, t_room *head)
{
	char	*name2;
	int 	i;

	name2 = ft_strjoin(name, "-");
	i = 0;
	while(con->name[i] != '-')
		i++;
	if (ft_strstr(con->name, name2))
	{
		ft_strdel(&name2);
		name2 = ft_strscpy(con->name, ++i);
	}
	else
	{
		ft_bzero(name2, ft_strlen(name2));
		name2 = ft_strncpy(con->name, i);
	}
	while(head)
	{
		if(ft_strcmp(head->name, name2) == 0)
			break;
		head = head->next;
	}
	ft_strdel(&name2);
	return (head);
}

void	print_end(t_room *room)
{
	int i;

	i = 0;
	if (room != g_ants.end)
		return;
	while (g_ants.end->conn[i])
		i++;
	if (i == 0)
		ft_printf("conn NULL\n");
	else
		ft_printf("conn not NULL\n");

}

void    addcontorom(char *name, t_con *head)
{
    int     i;
    int    con;

	con = 0;
    while(g_ants.rhead)
    {
        if (!ft_strcmp(g_ants.rhead->name, name))
            break;
        g_ants.rhead = g_ants.rhead->next;
    }
    if (!g_ants.rhead)
        return ;
	con = countconnroom(g_ants.rhead->name, g_ants.chead);
	if (con == 0)
		return ;
	g_ants.rhead->conn = (t_room**)malloc(sizeof(t_room*) * (con + 1));
    i = -1;
    while(head)
	{
		if (ft_strstr(head->name, name))
			g_ants.rhead->conn[++i] = findroombycon(name, head, headofroom(g_ants.rhead));
		head = head->next;
	}
    g_ants.rhead->conn[con] = NULL;
    g_ants.rhead = headofroom(g_ants.rhead);
}

void    pars_con(void)
{
    g_ants.room = headofroom(g_ants.room);
    while(g_ants.room)
    {
        addcontorom(g_ants.room->name, g_ants.chead);
        g_ants.room->curant = 0;
        g_ants.room->path = 0;
        g_ants.room->ant = 0;
        g_ants.room->onway = 0;
		g_ants.chead = headofcon(g_ants.chead);
		if (!g_ants.room->next)
			break;
        g_ants.room = g_ants.room->next;
    }
}

