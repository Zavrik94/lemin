/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azavrazh <azavrazh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 17:30:23 by azavrazh          #+#    #+#             */
/*   Updated: 2018/10/28 18:17:02 by azavrazh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

int		main(int ac, const char **av)
{
	const int		fd = iterate_flags(ac, av);

	if (fd == -1)
		ft_error("Can not open file");
	ft_read(fd);
	pars_con();
	path(g_ants.start, g_ants.end);
	ways();
	if (!g_ants.flags.silent)
		print_map();
	if (g_ants.flags.ways)
		printways();
	move();
	return (0);
}
