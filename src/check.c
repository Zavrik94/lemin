#include <lemin.h>

int     check_room(char *str)
{
    int		i;
    int		spc;
    char	**chk;

    i = -1;
    spc = 0;
    while (str[++i])
        if (str[i] == ' ')
            spc++;
    if (spc != 2)
        return (0);
    chk = ft_strsplit(str, ' ');
    i = 0;
    while (chk[i])
        i++;
    if (i != 3 || (!ft_isnum(chk[1]) || !ft_isnum(chk[2]))
        || (chk[0][0] == 'L' || chk[0][0] == '#'))
    {
    	delaftersplit(&chk);
		return (0);
	}
    i = -1;
    while (chk[0][++i])
        if (chk[0][i] == ' ' || chk[0][i] == '\t' || chk[0][i] == '-')
        {
        	delaftersplit(&chk);
			return (0);
		}
	delaftersplit(&chk);
    return (1);
}

void     check_con(char *str)
{
    int		i;
    int		t;
    char	*name1;
    char	*name2;

    i = -1;
    t = 0;
    while (str[++i])
        if (str[i] == '-')
            t++;
        else if (str[i] == ' ' || str[i] == '\t')
            ft_error("wrong connection format");
    if (t != 1)
        ft_error("wrong connection format");
    i = -1;
    while (str[++i])
        if (str[i] == '-')
            break;
    name1 = ft_strncpy(str, i);
    name2 = ft_strscpy(str, ++i);
    if (!findroombyname(name2) || !findroombyname(name1))
    {
    	ft_strdel(&name1);
    	ft_strdel(&name2);
		ft_error("connection with unknown room");
	}
	ft_strdel(&name1);
	ft_strdel(&name2);
}

int 	check_coord(int	x, int y, char *name)
{
	t_room *head;

	head = headofroom(g_ants.room);
	while (head)
	{
		if (x == head->x && y == head->y && ft_strcmp(name, head->name))
			return (1);
		head = head->next;
	}
	return (0);
}

int 	havethisconn(char *roomname, t_con *conn)
{
	t_room *room;
	int 	i;

	room = findroombyname(roomname);
	i = -1;
	if (room->conn == NULL)
		return (0);
	while (room->conn[++i])
	{
		if (room->conn[i] == findroombycon(roomname, conn, headofroom(g_ants.room)))
			return (1);
	}
	return (0);
}
