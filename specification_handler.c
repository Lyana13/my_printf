#include "ft_printf.h"

void transform_specification(t_spec *s, va_list args, t_buff *buff) {

}

int parse_specification_opts(char *spec, t_spec *s)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (1)
	{
		i = i + len;
		if (len = parse_flags(spec + i, s))
			continue;
		else if (len = parse_width(spec + i, s))
			continue;
		else if (len = parse_precision(spec + i, s))
			continue;
		else if (len = parse_length_modifier(spec + i, s))
			continue;
		else
			return (i);
	}
}

void init_spec(t_spec *spec)
{
	spec->flags = 0;
	spec->width = 0;
	spec->precision = 1;
	spec->length_modifier = H;
	spec->specifier = 0;
}

int handle_specification(char *spec, va_list args, t_buff *buff)
{
	t_spec s;
	int len;

	init_spec(&s);
	len = parse_specification_opts(spec, &s);
	if (parse_specifier(spec + len, &s)) {
		transform_specification(&s, args, buff);
		len++;
	}
	return (len);
}
