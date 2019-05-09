#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdint.h>
#include <stdarg.h>
#include <stdlib.h>
#include "libft.h"

#define FT_PRINTF_FLAG_HASH 1
#define FT_PRINTF_FLAG_ZERO 2
#define FT_PRINTF_FLAG_PLUS 4
#define FT_PRINTF_FLAG_MINUS 8
#define FT_PRINTF_FLAG_SPACE 16

typedef enum e_length_modifier {
	H,
	HH,
	L,
	LL
} t_length_modifier;

typedef struct s_spec {
	char flags;
	int width;
	int precision;
	t_length_modifier length_modifier;
	char specifier;
} t_spec;

typedef struct s_buff
{
	char data[4096];
	int pos;	
} t_buff;


void init_buff(t_buff *buff);
void write_buff(char *c, int len, t_buff *buff);
void flush_buff(t_buff *buff);
int buff_size(t_buff *buff);

int handle_specification(char *spec, va_list args, t_buff *buff);

int parse_flags(char *spec, t_spec *s);
int parse_width(char *spec, t_spec *s);
int parse_precision(char *spec, t_spec *s);
int parse_length_modifier(char *spec, t_spec *s);
int parse_specifier(char *spec, t_spec *s);
