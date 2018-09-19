#include <lemin.h>

void *freelastconn(t_files *head)
{
	while(head)
	{
		if (ft_strcmp(head->temp, "\0") == 0)
			return (head);
		head = head->next;
	}
	return (NULL);
}

t_files     *findinconn(t_files *head, char *str)
{
    while(head)
    {
        if (ft_strcmp(head->temp, str))
            return (head);
        head = head->next;
    }
    return (NULL);
}