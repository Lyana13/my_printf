#include "ft_printf.h"

void convert_spec(t_spec *s, va_list args, t_buff *buff) {
	static t_converter (converters[3]) = {
		{ .conversions = "s", .converter = &convert_string },
		{ .conversions = "c%", .converter = &convert_char },
		{ .conversions = "pdiouxXb", .converter = &convert_int }
		// { .conversions = "f", .converter = &float_converter },
	};
	int i;

	i = 0;
	while (i < 3){
		if (ft_strchr(converters[i].conversions, s->specifier)){
			converters[i].converter(s, args, buff);
			break;
		}
		i++;
	}	
}

int parse_spec_opts(char *spec, t_spec *s)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (1)
	{
		i = i + len;
		if ((len = parse_flags(spec + i, s)))
			continue;
		else if ((len = parse_width(spec + i, s)))
			continue;
		else if ((len = parse_precision(spec + i, s)))
			continue;
		else if ((len = parse_length_modifier(spec + i, s)))
			continue;
		else
			return (i);
	}
}

void init_spec(t_spec *spec)
{
	spec->flags = 0;
	spec->width = 0;
	spec->precision = INIT_PRECISION;
	spec->length_modifier = H;
	spec->specifier = 0;
}

void correct_spec(t_spec *s) {
	if (s->precision == INIT_PRECISION && ft_strrchr("diouxX", s->specifier)) 
		s->precision = 1;
	else if (s->precision == INIT_PRECISION && ft_strrchr("fF", s->specifier))
		s->precision = 6;
}

int handle_specification(char *spec, va_list args, t_buff *buff)
{
	t_spec s;
	int len;

	init_spec(&s);
	len = parse_spec_opts(spec, &s);
	if (parse_specifier(spec + len, &s)) {
		correct_spec(&s);
		convert_spec(&s, args, buff);
		len++;
	}
	return (len);
}
