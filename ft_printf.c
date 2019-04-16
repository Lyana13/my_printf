#include "ft_printf.h"

static void		lengths(int n, size_t *len, int *weight)
{
	*len = 1;
	if (n >= 0)
	{
		*len = 0;
		n = -n;
	}
	*weight = 1;
	while (n / *weight < -9)
	{
		*weight *= 10;
		*len += 1;
	}
}

char			*ft_itoa(int n)
{
	size_t		len;
	int			weight;
	size_t		cur;
	char		*str;

	lengths(n, &len, &weight);
	str = (char *)malloc(sizeof(*str) * (len + 1));
	if (str == NULL)
		return (NULL);
	cur = 0;
	if (n < 0)
	{
		str[cur] = '-';
		cur++;
	}
	if (n > 0)
		n = -n;
	while (weight >= 1)
	{
		str[cur++] = -(n / weight % 10) + 48;
		weight /= 10;
	}
	str[cur] = '\0';
	return (str);
}

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while(str[i])
		write(1, &str[i++], 1);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
		ft_putstr("-2147483648");
	else
	{
		if (n < 0)
		{
			ft_putchar('-');
			n *= -1;
		}
		if (n >= 10)
			ft_putnbr(n / 10);
		ft_putchar((n % 10) + '0');
	}
}

int ft_strlen(char *s)
{
    int i;

    i = 0;
    while (s[i])
    	i++;
    return (i);
}

int write_float_to_string(double num, int pres){
	int int_part;
	double dec_part;
	int len;

	if (num < 0){
		num *= -1;
		ft_putchar('-');
	}
	int_part = (int)num;
	dec_part = num - int_part;
	ft_putnbr(int_part);
	if (pres > 0)
		ft_putchar('.');
	len++;
	while (pres > 0) {
		dec_part *= 10;
		ft_putchar((int)dec_part + '0');
		dec_part -= (int)dec_part;
		pres--;
	len++;
	}
	return len;
}


int write_str(const char *str){
	int l;
	l = 0;
	while (str[l] != '\0')
		l++;
	return (write(1, str, l));
}

int write_char(const int c){
	return (write(1, &c, 1));
}

void rec_put_nbr(int64_t num){
	if (num > 10)
		rec_put_nbr(num / 10);
	num = num % 10 + '0';
	write(1, &num, 1);
}

int num_len(int64_t num)
{
	int len = 1;
	while (num /= 10)
		len++;
	return (len);
}

int write_num(int64_t num){
	if (num == -1 - 9223372036854775807L)
		return (write(1, "-922372036854775808", 20));
	else if (num < 0)
	{
		write(1, "-", 1);
		rec_put_nbr(-num);
		return (num_len(-num) + 1);
	}
	rec_put_nbr(num);
	return (num_len(num));

}
int parse_format(const char *format, va_list ap){
	int len = 0;

	int i = 0;
	while(format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			// check_all();
			if (format[i] == 's')
				len += write_str(va_arg(ap, char *));
			else if (format[i] == 'c')
				len += write_char(va_arg(ap, int32_t));
			else if (format[i] == 'd')
				len += write_num(va_arg(ap, int32_t));
			else if (format[i] == 'l' && ++i)
				len += write_num(va_arg(ap, int64_t));
			else if (format[i] == 'f')
				len += write_float_to_string(va_arg(ap, double), 6);

			// else if (format[i] == 'p' && ++i)
			// 	len += write_(va_arg(ap, int64_t));
			// else if (format[i] == 'i' && ++i)
			// 	len += write_(va_arg(ap, int64_t));
			// else if (format[i] == 'o' && ++i)
			// 	len += write_(va_arg(ap, int64_t));
			// else if (format[i] == 'u' && ++i)
			// 	len += write_(va_arg(ap, int64_t));
			// else if (format[i] == 'x' && ++i)
			// 	len += write_(va_arg(ap, int64_t));
			// else if (format[i] == 'X' && ++i)
			// 	len += write_(va_arg(ap, int64_t));
			// else if (format[i] == 'hh' && ++i)
			// 	len += write_(va_arg(ap, int64_t));
			// else if (format[i] == 'h' && ++i)
			// 	len += write_(va_arg(ap, int64_t));
			// else if (format[i] == 'l' && ++i)
			// 	len += write_(va_arg(ap, int64_t));
			// else if (format[i] == 'll' && ++i)
			// 	len += write_(va_arg(ap, int64_t));
			//else if (format[i] == 'h')
			//len += write_hexa(va_arg(ap, ))

		}
		else
			len += write(1, &format[i], 1);
		i++;
	}
	return len;
}

int ft_printf(const char *format, ...)
{
	int res;
	va_list ap;

	va_start(ap, format);
	res = parse_format(format, ap);
	va_end(ap);
	return res;
}

void set_width(t_state *state)
{
	state->params.width = 22;
}

int main(void){
	t_state ponatnoe;

	ponatnoe.buff[0] = 'l';
	ponatnoe.buff[1] = 'u';
	ponatnoe.buff[2] = '\0';
	// ponatnoe.params.width = 123;
	set_width(&ponatnoe);
	int si = printf(".%s, %ld, %ld, %ld, %ld, %s, %c, %d, %.2f, %d\n", "abc", -1 -9223372036854775807L, 92233720368L, -9223372036855807L, 24245L, "lolo", '+', +24, 300.936, 100);
	int mi = ft_printf(".%s, %ld, %ld, %ld, %ld, %s, %c, %d, %.2f, %d\n", "abc", -1 -9223372036854775807L, 92233720368L, -9223372036855807L, 24245L, "lolo", '+', +24, 300.936, 100);
	// printf("%d %d\n", mi, si);
	printf("%s\n, %d\n",  ponatnoe.buff, ponatnoe.params.width);

}
