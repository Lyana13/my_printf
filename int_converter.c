#include "ft_printf.h"

char* create_prefix(t_spec *s, char *num){
	if (num[0] == '0')
		return ft_strdup("");
	if (s->specifier == 'p')
		return ft_strdup("0x");
	if (s->flags & FT_PRINTF_FLAG_HASH){
		if (s->specifier == 'o')
			return ft_strdup("0");
		else if (s->specifier == 'x')
			return ft_strdup("0x");
		else if (s->specifier == 'X')
			return ft_strdup("0X");
	}
	return ft_strdup("");
}

int calc_width(t_spec *s, t_int_convert *ic){
	int width;

	width = s->precision > ic->num_len ? s->precision : ic->num_len;
	width += ic->prefix_len;
	if (ft_strchr("diou", s->specifier) &&
		(ic->sign == '-' ||
		 (ic->sign == '+' && (s->flags & FT_PRINTF_FLAG_PLUS ||
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

void init_converter(t_spec *s, va_list args, t_int_convert *ic){
	ic->num = get_ascci_int(s, args, &(ic->sign));
	ic->num_len = ft_strlen(ic->num);
	ic->prefix = create_prefix(s, ic->num);
	ic->width = calc_width(s, ic);
	ic->prefix_len = ft_strlen(ic->prefix);
}

void cleanup_converter(t_int_convert *ic){
	free(ic->num);
	free(ic->prefix);
}

void convert_int(t_spec *s, va_list args, t_buff *buff) {
	t_int_convert ic;

	init_converter(s, args, &ic);
	if (s->flags & FT_PRINTF_FLAG_ZERO)
		write_buff(ic.prefix, ic.prefix_len, buff);
	maybe_write_width_left(s, ic.width, buff);
	if (!(s->flags & FT_PRINTF_FLAG_ZERO))
		write_buff(ic.prefix, ic.prefix_len, buff);
	maybe_write_sign(s, ic.sign, buff);
	maybe_write_precision(s, ic.num_len, buff);
	write_buff(ic.num, ic.num_len, buff);
	maybe_write_width_right(s, ic.width, buff);
	cleanup_converter(&ic);
}