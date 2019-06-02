#include "ft_printf.h"

void init_buff(t_buff *buff) {
	buff->size = 256;
	buff->data = malloc(buff->size);
	buff->pos = 0; 
}

void write_buff(char *c, int len, t_buff *buff) {
	char *tmp;

	while(len > 0) {
		if (buff->pos == buff->size) {
			tmp = malloc(buff->size * 2);
			ft_memcpy(tmp, buff->data, buff->size);
			free(buff->data);
			buff->data = tmp;
			buff->size *= 2;
		}
		buff->data[buff->pos] = *c;
		buff->pos++;
		c++;
		len--;
	}
}

void write_char_buff(char c, t_buff *buff) {
	write_buff(&c, 1, buff);
}

void flush_buff(t_buff *buff){
	write(1, buff->data, buff->pos);
	buff->pos = 0;
}

int buff_size(t_buff *buff){
	return (buff->pos);
}
