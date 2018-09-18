/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printarr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azavrazh <azavrazh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 20:34:39 by azavrazh          #+#    #+#             */
/*   Updated: 2018/09/12 20:34:39 by azavrazh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printarr_fd(int fd, char **arr)
{
	int i;

	i = -1;
	while (arr[++i])
	{
		ft_putstr_fd(arr[i], fd);
		ft_putchar_fd('\n', fd);
	}
}
