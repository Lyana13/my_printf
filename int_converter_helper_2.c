#include "ft_printf.h"

int is_signed(t_spec *s){
	return ft_strchr("di", s->specifier) ? 1 : 0;
}

long long int get_signed_int(t_spec *s, va_list args){
	if (s->length_modifier == H)
		return va_arg(args, short int);
	if (s->length_modifier == HH)
		return va_arg(args, char);
	if (s->length_modifier == L)
		return va_arg(args, long int);
	if (s->length_modifier == LL)
		return va_arg(args, long long int);
	return va_arg(args, int);

}
unsigned long long int get_unsigned_int(t_spec *s, va_list args){
	if (s->length_modifier == H)
		return va_arg(args, unsigned short int);
	if (s->length_modifier == HH)
		return va_arg(args, unsigned char);
	if (s->length_modifier == L)
		return va_arg(args, unsigned long int);
	if (s->length_modifier == LL)
		return va_arg(args, unsigned long long int);
	return va_arg(args, unsigned int);
}

unsigned long long int get_int(t_spec *s, va_list args, char *sign) {
	long long int i;

	if (is_signed(s)) {
		i = get_signed_int(s, args);
		printf("%d\n",i );
		*sign = (i < 0) ? '-' : '+';
		return ((unsigned long long int)(i < 0 ? -i : i));
	}
	else {
		*sign = '+';
		return get_unsigned_int(s, args);
	}
}