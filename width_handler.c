/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalaya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 10:29:44 by lmalaya           #+#    #+#             */
/*   Updated: 2019/07/08 10:29:46 by lmalaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_width(t_spec *s, int len, t_buff *buff)
{
	char	c;
	int		i;

	i = s->width - len;
	if (s->flags & FT_PRINTF_FLAG_ZERO &&
		!(s->flags & FT_PRINTF_FLAG_MINUS) &&
		ft_strchr("diouxXfFcps%", s->specifier))
		c = '0';
	else
		c = ' ';
	while (i > 0)
	{
		write_char_buff(c, buff);
		i--;
	}
}

void	maybe_write_width_left(t_spec *s, int len, t_buff *buff)
{
	if (!(s->flags & FT_PRINTF_FLAG_MINUS))
	{
		write_width(s, len, buff);
	}
}

void	maybe_write_width_right(t_spec *s, int len, t_buff *buff)
{
	if (s->flags & FT_PRINTF_FLAG_MINUS)
	{
		write_width(s, len, buff);
	}
}
