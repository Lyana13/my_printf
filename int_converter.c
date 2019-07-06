#include "ft_printf.h"


void maybe_write_precision(t_spec *s, int len, t_buff *buff){
	int i;

	i = s->precision - len;
	while(i > 0) {
		i--;
		write_char_buff('0', buff);
	}
}

void maybe_write_sign(t_spec *s, char sign, t_buff *buff){
	if(!ft_strchr("diopfF", s->specifier))
		return ;
	if (sign == '+' && s->flags & FT_PRINTF_FLAG_PLUS)
		write_char_buff('+', buff);
	else if (sign == '+' && s->flags & FT_PRINTF_FLAG_SPACE)
		write_char_buff(' ', buff);
	else if (sign == '-')
		write_char_buff('-', buff);
}


void cleanup_converter(t_int_convert *ic){
	free(ic->num);
	free(ic->prefix);
}

void convert_int(t_spec *s, va_list args, t_buff *buff) {
	t_int_convert ic;

	init_converter(s, args, &ic);
	if (s->flags & FT_PRINTF_FLAG_ZERO){
		write_buff(ic.prefix, ic.prefix_len, buff);
		maybe_write_sign(s, ic.sign, buff);
		}
	maybe_write_width_left(s, ic.width, buff);
	if (!(s->flags & FT_PRINTF_FLAG_ZERO)){
		write_buff(ic.prefix, ic.prefix_len, buff);
		maybe_write_sign(s, ic.sign, buff);
	}
	maybe_write_precision(s, ic.num_len, buff);
	write_buff(ic.num, ic.num_len, buff);
	maybe_write_width_right(s, ic.width, buff);
	cleanup_converter(&ic);
}