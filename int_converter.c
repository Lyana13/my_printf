#include "ft_printf.h"

int define_base(t_spec *s){
	if (ft_strchr("xX", s->specifier))
		return 16;
	if (ft_strchr("diu", s->specifier))
		return 10;
	if (s->specifier == 'o')
		return 8;
	if (s->specifier == 'b')
		return 2;
	return 10;
}

char *define_symbols(t_spec *s){
	static char *upper = "0123456789ABCDEF";
	static char *lower = "0123456789abcdef";

	return s->specifier == 'X' ? upper : lower;
}


void convert_int(t_spec *s, va_list args, t_buff *buff) {
	int base;
	char *symbols;


	base = define_base(s);
	symbols = define_symbols(s);
}