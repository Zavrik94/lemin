/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azavrazh <azavrazh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 18:37:08 by azavrazh          #+#    #+#             */
/*   Updated: 2018/10/28 21:35:16 by azavrazh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *haystack, const char *needle)
{
	int				i;
	int				count;
	int				k;
	unsigned char	*d1;
	unsigned char	*d2;

	d1 = (unsigned char *)haystack;
	d2 = (unsigned char *)needle;
	count = 0;
	i = 0;
	while (d2[count])
		count++;
	while (d1[i] || count == 0)
	{
		k = 0;
		while (d1[i + k] == d2[k] || count == 0)
		{
			if (k == count - 1 || count == 0)
				return ((char *)haystack + i);
			k++;
		}
		i++;
	}
	return (0);
}
