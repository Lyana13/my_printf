#include "ft_printf.h"

void float_converter(t_spec *s, va_list args, t_buff *buff){
	float num;

	num = va_arg(args, double);
	printf("%f\n", num);
	if (s == (t_spec *)buff)
		return;
}