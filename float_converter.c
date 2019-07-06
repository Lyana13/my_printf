#include "ft_printf.h"

void float_converter(t_spec *s, va_list args, t_buff *buff){
	double num;
	long long int int_part;
	double dec_part;
	char sign;
	char* int_part_str;

	num = va_arg(args, double);
	sign = num < 0 ? '-' : '+';
	num  = num < 0 ? -num : num ;
	int_part = (long long int)num;
	maybe_write_sign(s, sign, buff);
	int_part_str = int_to_string(int_part, s);
	write_buff(int_part_str, ft_strlen(int_part_str), buff);
	if (s->precision != 0)
		write_char_buff('.', buff);
	dec_part = num - int_part;
	while(s->precision > 0){
		dec_part *= 10;
		write_buff(dec_part, ft_strlen(dec_part), buff);
		s->precision --;
	}
	printf("%f\n", dec_part);
	// 	printf("%c\n", sign);
	if (s == (t_spec *)buff)
		return;
}