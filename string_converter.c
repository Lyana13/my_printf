/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_converter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalaya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 10:29:36 by lmalaya           #+#    #+#             */
/*   Updated: 2019/07/08 10:29:38 by lmalaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		calc_len(char *str, t_spec *s)
{
	int		len;

	if (str == NULL)
		return (6);
	len = ft_strlen(str);
	if (s->precision != INIT_PRECISION && s->precision < len)
		return (s->precision);
	else
		return (len);
}

void	convert_string(t_spec *s, va_list args, t_buff *buff)
{
	char	*str;
	int		len;

	str = va_arg(args, char *);
	len = calc_len(str, s);
	maybe_write_width_left(s, len, buff);
	write_buff(str ? str : "(null)", len, buff);
	maybe_write_width_right(s, len, buff);
}
