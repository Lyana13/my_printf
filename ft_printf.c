/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalaya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 10:27:58 by lmalaya           #+#    #+#             */
/*   Updated: 2019/07/08 13:06:45 by lmalaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_ordinary_char(char *c, t_buff *buff)
{
	write_buff(c, 1, buff);
	return (1);
}

void	handle_format(char *format, va_list args, t_buff *buff)
{
	int	i;
	int len;

	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			len = handle_specification(format + i, args, buff);
		}
		else
			len = handle_ordinary_char(format + i, buff);
		i = i + len;
	}
}

int		ft_printf(const char *format, ...)
{
	t_buff	buff;
	int		size;
	va_list	args;

	init_buff(&buff);
	va_start(args, format);
	handle_format((char*)format, args, &buff);
	va_end(args);
	size = buff_size(&buff);
	flush_buff(&buff);
	free(buff.data);
	return (size);
}
