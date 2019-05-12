#include "ft_printf.h"

unsigned char get_char(t_spec *s, va_list args) {
	if (s->specifier == 'c') {
		return (unsigned char)va_arg(args, int);
	}
	else if (s->specifier == '%') {
		return '%';
	}
	return 0;
}

void convert_char(t_spec *s, va_list args, t_buff *buff) {
	maybe_write_width_left(s, 1, buff);
	write_char_buff(get_char(s, args), buff);
	maybe_write_width_right(s, 1, buff);
}
