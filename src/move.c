#include <lemin.h>

t_room  *findbestway(t_room *room)
{
    int     i;
    int     min;
    int     cnt;

    min = g_ants.start->path;
    i = -1;
    cnt = 0;
    while (room->conn[++i])
        if (room->conn[i]->path < min)
        {
            min = room->conn[i]->path;
            cnt = i;
        }
    return (room->conn[cnt]);
}

void    move(void)
{
    t_room *curroom;
    t_room *nextroom;
    t_room *head;
    int     curant;

    g_ants.start->curant = 1;
    while (g_ants.end->curant != g_ants.antcnt)
    {
        curroom = g_ants.end;
        while (curroom != g_ants.start)
        {
            if (curroom->curant != 0)
            {
                nextroom = findbestway(curroom);
                nextroom->curant = curroom->curant;
                if (curroom == g_ants.start)
                    curroom->curant += 1;
                else
                    curroom->curant = 0;
                ft_printf("L%d-%s ", nextroom->curant, nextroom->name);
            }
            curroom = findbestway(curroom);
        }
        ft_printf("\n");
    }
}
