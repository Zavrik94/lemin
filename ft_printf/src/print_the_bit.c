/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_the_bit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azavrazh <azavrazh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 19:08:32 by azavrazh          #+#    #+#             */
/*   Updated: 2018/09/10 19:08:33 by azavrazh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void			print_the_bit(size_t b)
{
	char				arr[MAXINTSIZE];
	unsigned char		i;

	i = 0;
	while (b != 0 && i < MAXINTSIZE)
	{
		arr[i++] = b & 1 ? '1' : '0';
		b >>= 1;
	}
	while (i)
		ft_putchar(arr[--i]);
}
