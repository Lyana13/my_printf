#include "ft_printf.h"

void convert_char(t_spec *s, va_list args, t_buff *buff) {
	if (s->specifier == '%')
		write_char_buff('%', buff);
	else {
		maybe_write_width_left(s, 1, buff);
		write_char_buff((unsigned char)va_arg(args, int), buff);
		maybe_write_width_right(s, 1, buff);
	}
}
