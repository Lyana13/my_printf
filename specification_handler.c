/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specification_handler.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalaya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 10:29:01 by lmalaya           #+#    #+#             */
/*   Updated: 2019/07/08 22:36:28 by lmalaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					convert_spec(t_spec *s, va_list args, t_buff *buff)
{
	int					i;
	static t_converter	converters[4] =
	{ {"s", &convert_string}, {"c%", &convert_char},
	{"pdiouxXb", &convert_int}, {"fF", &float_converter}};

	i = 0;
	while (i < 4)
	{
		if (ft_strchr(converters[i].conversions, s->specifier))
		{
			converters[i].converter(s, args, buff);
			break ;
		}
		i++;
	}
}

int						parse_spec_opts(char *spec, t_spec *s)
{
	int					i;
	int					len;

	i = 0;
	len = 0;
	while (1)
	{
		i = i + len;
		if ((len = parse_flags(spec + i, s)))
			continue;
		else if ((len = parse_width(spec + i, s)))
			continue;
		else if ((len = parse_precision(spec + i, s)))
			continue;
		else if ((len = parse_length_modifier(spec + i, s)))
			continue;
		else
			return (i);
	}
}

void					init_spec(t_spec *spec)
{
	spec->flags = 0;
	spec->width = 0;
	spec->precision = INIT_PRECISION;
	spec->length_modifier = INIT;
	spec->specifier = 0;
}

void					correct_spec(t_spec *s)
{
	if (s->precision != INIT_PRECISION && ft_strchr("diouxX", s->specifier))
		s->flags = s->flags & ~(FT_PRINTF_FLAG_ZERO);
	if (s->precision == INIT_PRECISION && ft_strrchr("fF", s->specifier))
		s->precision = 6;
	if (s->specifier == 'p')
		s->length_modifier = L;
}

int						handle_specification(char *spec, va_list args,
	t_buff *buff)
{
	t_spec				s;
	int					len;

	if (*spec == '\0')
		return (0);
	init_spec(&s);
	len = parse_spec_opts(spec, &s);
	if (parse_specifier(spec + len, &s))
	{
		correct_spec(&s);
		convert_spec(&s, args, buff);
		len++;
	}
	return (len);
}
