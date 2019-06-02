#include "ft_printf.h"

void maybe_write_prefix(t_spec *s, char *num, t_buff *buff){
	if (num[0] == '0')
		return ;
	if (s->specifier == 'o')
		write_buff("0", 1, buff);
	else if (ft_strchr("xp", s->specifier))
		write_buff("0x", 2, buff);
	else if (s->specifier == 'X')
		write_buff("0X", 2, buff);
}

int calc_width(t_spec *s, char *num, char sign, int num_len){
	int width;

	width = s->precision > num_len ? s->precision : num_len;
	if (num[0] != '0') {
		if (s->specifier == 'o')
			width += 1;
		else if (ft_strchr("xXp", s->specifier))
			width += 2;
	}
	if (ft_strchr("diou", s->specifier) &&
		(sign == '-' ||
		 (sign == '+' && (s->flags & FT_PRINTF_FLAG_PLUS ||
		 	              s->flags & FT_PRINTF_FLAG_SPACE))))
		width += 1;
	return width;
}

void maybe_write_precision(t_spec *s, int len, t_buff *buff){
	int i;

	i = s->precision - len;
	while(i > 0) {
		i--;
		write_char_buff('0', buff);
	}
}

void maybe_write_sign(t_spec *s, char sign, t_buff *buff){
	if(!ft_strchr("dioup", s->specifier))
		return ;
	if (sign == '+' && s->flags & FT_PRINTF_FLAG_PLUS)
		write_char_buff('+', buff);
	else if (sign == '+' && s->flags & FT_PRINTF_FLAG_SPACE)
		write_char_buff(' ', buff);
	else if (sign == '-')
		write_char_buff('-', buff);
}

void convert_int(t_spec *s, va_list args, t_buff *buff) {
	char *num;
	char sign;
	int len;
	int width;

	num = get_ascci_int(s, args, &sign);
	len = ft_strlen(num);
	width = calc_width(s, num, sign, len);
	if (s->flags & FT_PRINTF_FLAG_ZERO)
		maybe_write_prefix(s, num, buff);
	maybe_write_width_left(s, width, buff);
	if (!(s->flags & FT_PRINTF_FLAG_ZERO))
		maybe_write_prefix(s, num, buff);
	maybe_write_sign(s, sign, buff);
	maybe_write_precision(s, len, buff);
	write_buff(num, len, buff);
	maybe_write_width_right(s, width, buff);
	free(num);
}