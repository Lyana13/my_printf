#include "ft_printf.h"

unsigned int define_base(t_spec *s){
	if (ft_strchr("xXp", s->specifier))
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

int count_len(unsigned long long int i, unsigned int base) {
	int len;

	len = 1;
	while (i >= base)
	{
		len++;
		i /= base;
	}
	return len;
} 

char *itoa_base(unsigned long long int i, unsigned int base, char *symbols) {
	int len;
	char *num;

	len = count_len(i, base);
	num = (char*)malloc(len + 1);
	num[len] = '\0';
	while (len > 0)
	{
		num[len - 1] = symbols[i % base];
		len--;
		i /= base;
	}
	return num;
}

char* int_to_string(unsigned long long int i, t_spec *s){
	return itoa_base(i, define_base(s), define_symbols(s));
}

void get_ascci_int(t_spec *s, va_list args, t_int_convert *ic) {

	ic->i = get_int(s, args, &(ic->sign));
	if(ic->i == 0 && s->precision == 0)
		ic->num = ft_strdup("");
	else
		ic->num = int_to_string(ic->i, s);

}