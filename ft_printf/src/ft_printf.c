/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azavrazh <azavrazh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 19:05:48 by azavrazh          #+#    #+#             */
/*   Updated: 2018/09/10 19:36:26 by azavrazh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void			add_char_to_buf(const int c, t_printf *p)
{
	if ((p->i + 1) == BUFFER_SIZE)
	{
		p->to_out += write(p->outfd, p->buf, p->i);
		p->i = 0;
	}
	p->buf[p->i++] = c;
}

int				ft_printf(const char *convstr, ...)
{
	size_t				i;
	static t_printf		p;
	static char			buf[BUFFER_SIZE];

	ft_bzero(&p, sizeof(p));
	p.outfd = 1;
	p.buf = buf;
	va_start(p.ap, convstr);
	i = 0;
	while (convstr[i] != '\0')
	{
		if (convstr[i] == '%')
			i = parseconvstr(convstr, i, &p);
		else
			add_char_to_buf(convstr[i++], &p);
	}
	va_end(p.ap);
	if (p.i > 0)
		p.to_out += write(p.outfd, p.buf, p.i);
	return (p.to_out);
}

int				ft_dprintf(int fd, const char *convstr, ...)
{
	size_t				i;
	static t_printf		p;
	static char			buf[BUFFER_SIZE];

	ft_bzero(&p, sizeof(p));
	p.outfd = fd;
	p.buf = buf;
	va_start(p.ap, convstr);
	i = 0;
	while (convstr[i] != '\0')
	{
		if (convstr[i] == '%')
			i = parseconvstr(convstr, i, &p);
		else
			add_char_to_buf(convstr[i++], &p);
	}
	va_end(p.ap);
	if (p.i > 0)
		p.to_out += write(p.outfd, p.buf, p.i);
	return (p.to_out);
}
