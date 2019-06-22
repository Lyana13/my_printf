#include "ft_printf.h"

int handle_ordinary_char(char *c, t_buff *buff) {
	write_buff(c, 1, buff);
	return (1);
}

void handle_format(char *format, va_list args, t_buff *buff)
{
	int i;
	int len;

	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%') {
			i++;
			len = handle_specification(format + i, args, buff);
		}
		else
			len = handle_ordinary_char(format + i, buff); 
		i = i + len;
	}
}

int ft_printf(const char *format, ...)
{
	t_buff buff;
	int size;
	va_list args;

	init_buff(&buff);
	va_start(args, format);
	handle_format((char*)format, args, &buff);
	va_end(args);
	size = buff_size(&buff);
	flush_buff(&buff);
	return size;
}

int main(void){
	// t_state ponatnoe;

	// ponatnoe.buff[0] = 'l';
	// ponatnoe.buff[1] = 'u';
	// ponatnoe.buff[2] = '\0';
	// ponatnoe.params.width = 123;
	// set_width(&ponatnoe);
	// int si = printf(".%s, %ld, %ld, %ld, %ld, %s, %c, %d, %.2f, %d\n", "abc", -1 -9223372036854775807L, 92233720368L, -9223372036855807L, 24245L, "lolo", '+', +24, 300.936, 100);
	// int mi = ft_printf(".%s, %ld, %ld, %ld, %ld, %s, %c, %d, %.2f, %d\n", "abc", -1 -9223372036854775807L, 92233720368L, -9223372036855807L, 24245L, "lolo", '+', +24, 300.936, 100);
	// printf("%d %d\n", mi, si);
	// printf("%s\n, %d\n",  ponatnoe.buff, ponatnoe.params.width);
	char *fmt = "%#o\n";
	ft_printf(fmt, 0);
	printf(fmt, 0);

}
