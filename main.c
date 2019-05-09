#include <stdio.h>

int main(void){
	char *str = "losar";
	char *new_str = str + 1;
	printf("%ld: %c\n", (size_t)str, *str);
	printf("%ld: %c\n", (size_t)new_str, *new_str);
	return (0);
}
