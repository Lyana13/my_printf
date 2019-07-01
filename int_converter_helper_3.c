#include "ft_printf.h"

char* create_prefix(t_spec *s, char *num){
	if (s->specifier == 'p')
		return ft_strdup("0x");
	if (num[0] == '0')
		return ft_strdup("");
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

void init_converter(t_spec *s, va_list args, t_int_convert *ic){
	ic->num = get_ascci_int(s, args, &(ic->sign));

	ic->num_len = ft_strlen(ic->num);
	ic->prefix = create_prefix(s, ic->num);
	ic->prefix_len = ft_strlen(ic->prefix);
	ic->width = calc_width(s, ic);
}