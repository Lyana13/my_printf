#include "ft_printf.h"

void init_buff(t_buff *buff) {
	buff->pos = 0; 
}

void write_buff(char *c, t_buff *buff){
	buff->data[buff->pos] = c;
	buff->pos++;
}

void flush_buff(t_buff *buff){
	write(1, buff->data, buf->pos);
	buff->pos = 0;
}

int buff_size(t_buff *buff){
	return (buff->pos);
}
