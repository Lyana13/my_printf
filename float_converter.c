#include "ft_printf.h"

unsigned int get_digit_after_point_at(unsigned int pos, double num){
	unsigned int i;
	unsigned int int_part;

	i = 0;
	while(i < pos - 1){
		num *= 10;
		int_part = (unsigned int)num;
		num -= int_part;
		i++;
	}
	return (unsigned int)(num * 10);
}

char *ft_strrev(char *str)
{
    char tmp;
    int i;
    int j;

    i = 0;
    j = ft_strlen(str) - 1;
    while (i < j)
    {
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
        j--;
        i++;
    }
    return (str);
}

char *put_dec_part(unsigned int prec, double num){
	char *buff;
	unsigned int round;
	unsigned int res;
	int i;

	i = 0;
	buff = ft_strnew(prec);
	round = get_digit_after_point_at(prec + 1, num) > 5 ? 1 : 0;
	while(prec > 0){
		res = get_digit_after_point_at(prec, num) + round;
		buff[i] = res % 10 + 48;
		round = res / 10;
		prec--;
		i++;
	}
	return ft_strrev(buff);
}

void float_converter(t_spec *s, va_list args, t_buff *buff){
	double num;
	char *dec_part_str;
	char sign;
	char* int_part_str;

	num = va_arg(args, double);
	sign = num < 0 ? '-' : '+';
	num  = num < 0 ? -num : num ;
	maybe_write_sign(s, sign, buff);
	int_part_str = int_to_string((long long int)num, s);
	write_buff(int_part_str, ft_strlen(int_part_str), buff);
	if (s->precision != 0)
		write_char_buff('.', buff);
	dec_part_str = put_dec_part(s->precision, num);
	write_buff(dec_part_str, ft_strlen(dec_part_str), buff);
	free(int_part_str);
	free(dec_part_str);
}