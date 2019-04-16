#include <stdio.h>


char	*ft_strchr(const char *s, int c){
	while (s[0] != c && s[0] != '\0')
		s++;
	if(s[0] == '\0')
		return (NULL);
	else
		return (char*)s;
}

int digit( int c){
	return (c >= '0' && c <= '9');
}

int flag(const char c)
{
	return(ft_strchr("-+ #0", c) != NULL);
}
int accuracy_type(const char c)
{
	return(ft_strchr("diouxXaAeEfFgGcsSpn", c) != NULL);
}
int precision(const char c)
{
	return(ft_strchr("*$.", c) != NULL);
}
int check_modifier(const char c)
{
	return(ft_strchr("hhllL", c) != NULL);
}
int check_all(const char c)
{
	return(flag(c) || accuracy_type(c) || precision(c) || check_modifier(c) || digit(c) ;
}

// int  main(void){
// 	int x = 'f';

// 	printf("%s\n", ft_strchr("liiifof", x));
// 	return 0;
// }
