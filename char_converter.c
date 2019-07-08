/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_converter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalaya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 10:27:19 by lmalaya           #+#    #+#             */
/*   Updated: 2019/07/08 22:44:20 by lmalaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned char	get_char(t_spec *s, va_list args)
{
	if (s->specifier == '%')
		return ('%');
	else
		return (unsigned char)va_arg(args, int);
}

void			convert_char(t_spec *s, va_list args, t_buff *buff)
{
	maybe_write_width_left(s, 1, buff);
	write_char_buff(get_char(s, args), buff);
	maybe_write_width_right(s, 1, buff);
}
