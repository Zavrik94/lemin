/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azavrazh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 18:42:43 by azavrazh          #+#    #+#             */
/*   Updated: 2017/12/07 18:42:44 by azavrazh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(const char *src, size_t n)
{
	char	*d;
	char	*s;
	size_t	i;

	i = 0;
	s = (char*)src;
	d = (char*)malloc(sizeof(char) * (n + 1));
	while (s[i] && i < n)
	{
		d[i] = s[i];
		i++;
	}
	d[n] = '\0';
	return (d);
}
