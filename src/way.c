#include <lemin.h>

t_room  *findbestway(t_room *room)
{
    int     i;
    int     min;
    int     cnt;

    min = g_ants.start->path;
    i = -1;
    cnt = -1;
    while (room->conn[++i])
        if (room->conn[i]->path < min && room->conn[i]->onway == 0)
        {
            min = room->conn[i]->path;
            cnt = i;
        }
    if (cnt == -1)
        return (NULL);
    return (room->conn[cnt]);
}

int     check_rooms()
{
    t_room  *start;
    int     i;

    i = -1;
    start = g_ants.start;
    while (start->conn[++i])
        if (start->conn[i]->onway == 0)
            return (0);
    return (1);
}

void    ways()
{
    t_room *start;
    int     i;

    i = 0;
    while (!check_rooms())
    {
        start = g_ants.start;
        while (start != g_ants.end)
        {
            start = findbestway(start);
            if (start == NULL)
                break;
            start->onway = i + 1;
        }
        i++;
    }
    g_ants.numofways = i;
}
