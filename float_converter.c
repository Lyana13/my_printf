/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_converter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalaya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 10:27:36 by lmalaya           #+#    #+#             */
/*   Updated: 2019/07/08 10:27:44 by lmalaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	get_digit_after_point_at(unsigned int pos, long double num)
{
	unsigned int	i;
	unsigned int	int_part;

	i = 0;

	num -= (unsigned long long int)num;
	while (i < pos - 1)
	{
		num *= 10;
		int_part = (unsigned int)num;
		num -= int_part;
		i++;
	}
	return (unsigned int)(num * 10);
}

int				put_dec_part(unsigned int prec, long double num, char *buff)
{
	unsigned int	round;
	unsigned int	res;
	int				i;

	i = 0;
	round = get_digit_after_point_at(prec + 1, num) > 5 ? 1 : 0;
	while (prec > 0)
	{
		res = get_digit_after_point_at(prec, num) + round;
		buff[i] = res % 10 + 48;
		round = res / 10;
		prec--;
		i++;
		
	}
	ft_strrev(buff);
	return (round);
}

int				calc_width_float(char sign, t_spec *s, char *int_part_str)
{
	int				width;

	width = is_sign_printable(sign, s) + ft_strlen(int_part_str);
	width += s->precision != 0 ? 1 : 0;
	return (width + s->precision);
}

long double get_float(t_spec *s, va_list args)
{
	if (s->length_modifier == LB)
		return (va_arg(args, long double));
	else
		return (va_arg(args, double));
}

void			float_converter(t_spec *s, va_list args, t_buff *buff)
{
	long double		num;
	char			*dec_part_str;
	char			sign;
	char			*int_part_str;
	int				width;

	num = get_float(s, args);
	sign = num < 0 ? '-' : '+';
	num = num < 0 ? -num : num;
	dec_part_str = ft_strnew(s->precision);
	num += put_dec_part(s->precision, num, dec_part_str);
	int_part_str = int_to_string((long long int)num, s);
	width = calc_width_float(sign, s, int_part_str);
	if (s->flags & FT_PRINTF_FLAG_ZERO)
		maybe_write_sign(s, sign, buff);
	maybe_write_width_left(s, width, buff);
	if (!(s->flags & FT_PRINTF_FLAG_ZERO))
		maybe_write_sign(s, sign, buff);
	write_buff(int_part_str, ft_strlen(int_part_str), buff);
	if (s->precision != 0)
		write_char_buff('.', buff);
	write_buff(dec_part_str, ft_strlen(dec_part_str), buff);
	maybe_write_width_right(s, width, buff);
	free(int_part_str);
	free(dec_part_str);
}
