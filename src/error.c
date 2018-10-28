/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azavrazh <azavrazh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 17:29:54 by azavrazh          #+#    #+#             */
/*   Updated: 2018/10/28 20:36:19 by azavrazh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

const char	*g_usage = "Usage: ./lem-in "
"[--silent] [--solo] [--ways] [--steps] [--help] (< file|file)\n"
"\t--silent : hide map in output\n"
"\t--solo : chose only one min path\n"
"\t--way : display all posible ways\n"
"\t--steps : display final steps\n"
"\t--help : look help information\n";

void		delaftersplit(char ***arr)
{
	int		i;
	char	**temp;

	i = -1;
	if (arr == NULL || *arr == NULL || **arr == NULL)
		return ;
	temp = *arr;
	while (temp[++i])
		if (temp[i] != NULL)
			ft_strdel(&temp[i]);
	free(temp);
}

bool		ft_error(char *err)
{
	if (!err)
		ft_putstr(g_usage);
	else
		ft_printf("%s\n", err);
	exit(0);
}
