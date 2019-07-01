#include "ft_printf.h"

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
	char *fmt = "%#.x  %#.x\n";
	ft_printf(fmt, 0, 0);
	printf(fmt, 0, 0);

}