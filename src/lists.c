/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azavrazh <azavrazh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 17:30:59 by azavrazh          #+#    #+#             */
/*   Updated: 2018/10/28 17:30:59 by azavrazh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

t_room	*findroombyname(char *name)
{
	t_room	*head;

	head = headofroom(g_ants.rhead);
	while (head)
	{
		if (head->name != NULL && !ft_strcmp(head->name, name))
			return (head);
		head = head->next;
	}
	return (NULL);
}

t_room	*headofroom(t_room *list)
{
	while (list->prev)
		list = list->prev;
	return (list);
}

t_con	*headofcon(t_con *list)
{
	while (list->prev)
		list = list->prev;
	return (list);
}
