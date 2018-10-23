#include <lemin.h>

t_room  *findprevonway(t_room *room, int num)
{
    int     i;
    int     max;
    t_room  *temp;

    i = -1;
    max = 0;
    while (room->conn[++i])
    {
        if (room->conn[i] == g_ants.start)
            return (room->conn[i]);
        if (room->conn[i]->onway == num)
        {
            if (max == 0)
            {
                temp = room->conn[i];
                max = room->path;
            }
            else
            {
                if (room->path > max)
                {
                    temp = room->conn[i];
                    max = room->path;
                }
            }
        }
    }
    return (temp);
}

char    *outstr(int ant, char *name)
{
    char    *tmp;

    tmp = "\0";
    tmp = ft_strjoin(tmp, "L");
    tmp = ft_strjoin(tmp, ft_itoa(ant));
    tmp = ft_strjoin(tmp, "-");
    tmp = ft_strjoin(tmp, name);
    tmp = ft_strjoin(tmp, " ");
    return tmp;
}

void    moveonway(int num)
{
    t_room *end;
    t_room *prev;
    char    *tmp;

    end = g_ants.end;
    tmp = "\0";
    while (end != g_ants.start)
    {
        prev = findprevonway(end, num);
        if (prev->ant > 0)
        {
            end->ant = prev->ant;
            if (prev == g_ants.start)
            {
                prev->ant++;
                if (prev->ant > g_ants.antcnt)
                    prev->ant = 0;
            }
            else
                prev->ant = 0;
            ft_printf("L%d-%s ", end->ant, end->name);

            /*if (tmp == "\0")
                tmp = ft_strjoin(outstr(end->ant, end->name), tmp);
            else
                tmp = ft_strjoin(outstr(end->ant, end->name), tmp);*/
        }
        end = prev;
    }
    //ft_printf("%s", tmp);
}

void    move(void)
    {
    t_room *curroom;
    t_room *nextroom;
    t_room *head;
    int     curant;
    int     i;

    g_ants.start->ant = 1;
    while (g_ants.end->ant != g_ants.antcnt)
    {
        i = 0;
        while (++i <= g_ants.numofways)
            moveonway(i);
        ft_printf("\n");
    }
}
