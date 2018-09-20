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

	name2 = ft_strcat(name, "-");
	i = 0;
	while(con->name[i] != '-')
		i++;
	if (ft_strstr(con->name, name2))
	{
		ft_strdel(&name2);
		name2 = ft_strscpy(con->name, i);
	}
	else
	{
		ft_bzero(name2, ft_strlen(name2));
		name2 = ft_strncpy(name2, con->name, --i);
	}
	while(head)
	{
		if(ft_strcmp(head->name, name2))
			break;
		head = head->next;
	}
	ft_strdel(&name2);
	return (head);
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
	g_ants.rhead->conn[con] = NULL;
    i = -1;
    while(head->next)
	{
		if (ft_strstr(head->name, name))
			g_ants.rhead->conn[++i] = findroombycon(name, head, headofroom(g_ants.rhead));
		head = head->next;
	}
}

void    pars_con(void)
{
    while(g_ants.rhead)
    {
        addcontorom(g_ants.room->name, g_ants.chead);
        if (!g_ants.rhead->next)
			break;
        g_ants.rhead = g_ants.rhead->next;
		g_ants.chead = headofcon(g_ants.chead);
    }
}

