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

typedef struct s_state
{
	t_params params;
	char buff[4096];	
} t_state;


int ft_treatment_char(t_params params, va_list ap);
int ft_treatment_percent(t_params params, va_list ap);
int ft_treatment_hex(t_params params, va_list ap);
int ft_treatment_string(t_params params, va_list ap);



