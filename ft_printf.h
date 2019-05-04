#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdint.h>
#include <stdarg.h>
#include <stdlib.h>


typedef struct s_params {
	int flags;
	int width;
	int precision;
	int length;
} t_params;

typedef struct s_buff
{
	char data[4096];
	int pos;	
} t_buff;


void init_buff(t_buff *buff);
void write_buff(char *c, t_buff *buff);
void flush_buff(t_buff *buff);
int buff_size(t_buff *buff);


int ft_treatment_char(t_params params, va_list ap);
int ft_treatment_percent(t_params params, va_list ap);
int ft_treatment_hex(t_params params, va_list ap);
int ft_treatment_string(t_params params, va_list ap);




