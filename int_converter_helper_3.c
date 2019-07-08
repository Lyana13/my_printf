/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_converter_helper_3.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalaya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 10:28:44 by lmalaya           #+#    #+#             */
/*   Updated: 2019/07/08 10:28:46 by lmalaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*create_prefix(t_spec *s, unsigned long long int i)
{
	if (s->specifier == 'p')
		return (ft_strdup("0x"));
	if (i == 0 && s->specifier != 'o')
		return (ft_strdup(""));
	if (s->flags & FT_PRINTF_FLAG_HASH)
	{
		if (s->specifier == 'o')
			return (ft_strdup("0"));
		else if (s->specifier == 'x')
			return (ft_strdup("0x"));
		else if (s->specifier == 'X')
			return (ft_strdup("0X"));
	}
	return (ft_strdup(""));
}

int		calc_width(t_spec *s, t_int_convert *ic)
{
	int width;

	width = s->precision > ic->num_len ? s->precision : ic->num_len;
	width += ic->prefix_len;
	if (ft_strchr("diou", s->specifier) &&
		(ic->sign == '-' ||
			(ic->sign == '+' && (s->flags & FT_PRINTF_FLAG_PLUS ||
			s->flags & FT_PRINTF_FLAG_SPACE))))
		width += 1;
	return (width);
}

void	init_converter(t_spec *s, va_list args, t_int_convert *ic)
{
	get_ascci_int(s, args, ic);
	ic->num_len = ft_strlen(ic->num);
	ic->prefix = create_prefix(s, ic->i);
	ic->prefix_len = ft_strlen(ic->prefix);
	ic->width = calc_width(s, ic);
}

void	get_ascci_int(t_spec *s, va_list args, t_int_convert *ic)
{
	ic->i = get_int(s, args, &(ic->sign));
	if (ic->i == 0 && s->precision == 0)
		ic->num = ft_strdup("");
	else
		ic->num = int_to_string(ic->i, s);
}
