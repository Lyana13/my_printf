#include "ft_printf.h"


int parse_flags(char *spec, t_spec *s)
{
	if (*spec == '#')
		s->flags |= FT_PRINTF_FLAG_HASH;
	else if (*spec == '0')
		s->flags |= FT_PRINTF_FLAG_ZERO;
	else if (*spec == '+')
		s->flags |= FT_PRINTF_FLAG_PLUS;
	else if (*spec == '-')
		s->flags |= FT_PRINTF_FLAG_MINUS;
	else if (*spec == ' ')
		s->flags |= FT_PRINTF_FLAG_SPACE;
	else
		return (0);
	return (1);
}

int parse_width(char *spec, t_spec *s)
{
	int i;
	int width;

	i = 0;
	if (ft_isdigit(spec[i])) {
		width = 0;	
		while (ft_isdigit(spec[i])) {
			width *= 10;
			width += spec[i] - '0';
			i++;
		}
		s->width = width;
	}
	return (i);
}

int parse_precision(char *spec, t_spec *s)
{
	int i;
	int precision;

	i = 0;
	if (spec[i] == '.') {
		i++;
		precision = 0;
		while (ft_isdigit(spec[i])) {
			precision *= 10;
			precision += spec[i] - '0';
			i++;
		}
		s->precision = precision;
	}
	return (i);
}

int parse_length_modifier(char *spec, t_spec *s)
{
	if (spec[0] == 'h' && spec[1] == 'h') {
		s->length_modifier = HH;
		return (2);
	}
	else if (spec[0] == 'h') {
		s->length_modifier = H;
		return (1);
	}
	else if (spec[0] == 'l' && spec[1] == 'l') {
		s->length_modifier = LL;
		return (2);
	}
	else if (spec[0] == 'l') {
		s->length_modifier = L;
		return (1);
	}
	return (0);
}

int parse_specifier(char *spec, t_spec *s)
{
	if (ft_strrchr("cspdiouxXf%", *spec) != NULL)
	{
		s->specifier = *spec;
		return (1);
	}
	return (0);
}