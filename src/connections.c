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

void    addcontorom(char *name)
{
    int     i;

    while(g_ants.rhead)
    {
        if (!ft_strcmp(g_ants.rhead->name, name))
            break;
        g_ants.rhead = g_ants.rhead->next;
    }
    if (!g_ants.rhead)
        return ;
    i = -1;
}

void    pars_con(void)
{
    int    con;

    con = 0;
    while(g_ants.rhead)
    {
        con = countconnroom(g_ants.rhead->name, g_ants.chead);
        g_ants.rhead->conn = (t_room**)malloc(sizeof(t_room*) * (con + 1));
        g_ants.rhead->conn[con] = NULL;
        addcontorom(g_ants.room->name);

        g_ants.rhead = g_ants.rhead->next;
    }
}

