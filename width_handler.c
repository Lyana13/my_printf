#include "ft_printf.h"

int precision_for_int_is_undefined(t_spec *s) {
	return (s->precision == INIT_PRECISION ||
		 	!ft_strchr("diouxX", s->specifier));
}

void write_width(t_spec *s, int len, t_buff *buff){
	char c;
	int i;

	i = s->width - len;
	if (s->flags & FT_PRINTF_FLAG_ZERO &&
		!(s->flags & FT_PRINTF_FLAG_MINUS) &&
		ft_strchr("diouxXfFc%", s->specifier) &&
		precision_for_int_is_undefined(s))
		c = '0';
	else
		c = ' ';
	while (i > 0) {
		write_char_buff(c, buff);
		i--;
	}
}

void maybe_write_width_left(t_spec *s, int len, t_buff *buff) {
	if (!(s->flags & FT_PRINTF_FLAG_MINUS)) {
		write_width(s, len, buff);
	}
}

void maybe_write_width_right(t_spec *s, int len, t_buff *buff){
	if (s->flags & FT_PRINTF_FLAG_MINUS) {
		write_width(s, len, buff);
	}
}

