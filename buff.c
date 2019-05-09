#include "ft_printf.h"

void init_buff(t_buff *buff) {
	buff->pos = 0; 
}

void write_buff(char *c, int len, t_buff *buff){
	while(len > 0) {
		buff->data[buff->pos] = *c;
		buff->pos++;
		c++;
		len--;
	}
}

void flush_buff(t_buff *buff){
	write(1, buff->data, buff->pos);
	buff->pos = 0;
}

int buff_size(t_buff *buff){
	return (buff->pos);
}
