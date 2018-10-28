#include <lemin.h>

int     checkzeropath(void)
{
    t_room	*head;

    head = headofroom(g_ants.room);
    while (head)
    {
        if (head->path == 0 && head != g_ants.start)
            return (1);
        head = head->next;
    }
    return (0);
}

int     haveway()
{
    t_room	*head;
    int		i;

    head = headofroom(g_ants.rhead);
    while (head)
    {
        i = -1;
        if (head->path == 0)
            while (head->conn[++i])
                if (head->conn[i]->path != 0)
                    return (1);
        head = head->next;
    }
    return (0);
}

void    checkaroundthisconn(t_room *room)
{
	int 	con;
	int     i = -1;

	con = countconnroom(room->name, headofcon(g_ants.conn));
	if (con < 3)
		return ;
	while (room->conn[++i])
	{
		if (room->conn[i]->path == 0 && room->conn[i] != g_ants.start)
			room->conn[i]->path = -1;
	}
}

void    path(t_room *start, t_room *end)
{
    t_room	*head;
    int		i;
    int		max;

    end->path = 1;
    while (checkzeropath() && (head = headofroom(g_ants.room)))
    {
        while (head)
        {
        	if (countconnroom(head->name, headofcon(g_ants.conn)) == 1 && head != g_ants.start && head != g_ants.end && head->conn[0])
				head->conn[0]->path = -1;
            else if (head->path != 0) {
                i = -1;
                while (head->conn[++i])
					if (head->conn[i]->path == 0 && head->conn[i] != start && head->path == -1)
						head->conn[i]->path = -1;
                    else if (head->conn[i]->path == 0 && head->conn[i] != start)
                    {
                        head->conn[i]->path = head->path + 1;
                        checkaroundthisconn(head->conn[i]);
                    }

            }
            head = head->next;
        }
        if (!haveway())
            ft_error("Has no way");
    }
    i = -1;
    max = 0;
    while (g_ants.start->conn[++i])
        if (g_ants.start->conn[i]->path > max)
            g_ants.start->path = max + 1;
}