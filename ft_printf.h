/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalaya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 10:42:31 by lmalaya           #+#    #+#             */
/*   Updated: 2019/07/08 22:39:40 by lmalaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdint.h>
# include <stdarg.h>
# include <stdlib.h>
# include "./libft/libft.h"

# define FT_PRINTF_FLAG_HASH 1
# define FT_PRINTF_FLAG_ZERO 2
# define FT_PRINTF_FLAG_PLUS 4
# define FT_PRINTF_FLAG_MINUS 8
# define FT_PRINTF_FLAG_SPACE 16
# define INIT_PRECISION -1

typedef enum				e_length_modifier
{
	INIT,
	H,
	HH,
	L,
	LL
}							t_length_modifier;

typedef struct				s_int_convert
{
	char					*num;
	int						num_len;
	char					sign;
	int						width;
	char					*prefix;
	int						prefix_len;
	unsigned long long int	i;
}							t_int_convert;

typedef struct				s_spec
{
	char					flags;
	int						width;
	int						precision;
	t_length_modifier		length_modifier;
	char					specifier;
}							t_spec;

typedef struct				s_buff
{
	char					*data;
	int						size;
	int						pos;
}							t_buff;

typedef struct				s_converter
{
	char					*conversions;
	void					(*converter)(t_spec*, va_list, t_buff*);
}							t_converter;

int							ft_printf(const char *format, ...);
void						init_buff(t_buff *buff);
void						write_buff(char *c, int len, t_buff *buff);
void						write_char_buff(char c, t_buff *buff);
void						flush_buff(t_buff *buff);
int							buff_size(t_buff *buff);
int							handle_specification(char *spec, va_list args,
	t_buff *buff);
void						maybe_write_width_left(t_spec *s, int len,
	t_buff *buff);
void						maybe_write_width_right(t_spec *s, int len,
	t_buff *buff);
int							parse_flags(char *spec, t_spec *s);
int							parse_width(char *spec, t_spec *s);
int							parse_precision(char *spec, t_spec *s);
int							parse_length_modifier(char *spec, t_spec *s);
int							parse_specifier(char *spec, t_spec *s);
void						convert_string(t_spec *s, va_list args,
	t_buff *buff);
void						convert_char(t_spec *s, va_list args,
	t_buff *buff);
void						convert_int(t_spec *s, va_list args,
	t_buff *buff);
void						float_converter(t_spec *s, va_list args,
	t_buff *buff);
void						get_ascci_int(t_spec *s, va_list args,
	t_int_convert *ic);
unsigned long long int		get_int(t_spec *s, va_list args, char *sign);
void						init_converter(t_spec *s, va_list args,
	t_int_convert *ic);
void						maybe_write_sign(t_spec *s, char sign,
	t_buff *buff);
char						*int_to_string(unsigned long long int i, t_spec *s);
unsigned int				get_digit_after_point_at(unsigned int pos,
	double num);

#endif
