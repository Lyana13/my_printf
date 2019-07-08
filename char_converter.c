/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_converter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalaya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 10:27:19 by lmalaya           #+#    #+#             */
/*   Updated: 2019/07/08 10:50:04 by lmalaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert_char(t_spec *s, va_list args, t_buff *buff)
{
	if (s->specifier == '%')
		write_char_buff('%', buff);
	else
	{
		maybe_write_width_left(s, 1, buff);
		write_char_buff((unsigned char)va_arg(args, int), buff);
		maybe_write_width_right(s, 1, buff);
	}
}
