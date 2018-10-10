#include <lemin.h>

int     checkzeropath(void)
{
    t_room *head;

    head = headofroom(g_ants.room);
    while (head)
    {
        if (head->path == 0)
            return (1);
        head = head->next;
    }
    return (0);
}

void    path(t_room *start, t_room *end)
{
    t_room *head;
    int    i;

    end->path = 1;
    while (checkzeropath())
    {
        head = headofroom(g_ants.room);
        while (head)
        {
            if (head->path > 0)
            {
                i = -1;
                while (head->conn[++i])
                    if (head->conn[i]->path == 0)
                        head->conn[i]->path = head->path + 1;
            }
            head= head->next;
        }
    }
}