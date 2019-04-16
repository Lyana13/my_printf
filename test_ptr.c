#include <stdio.h>

void increase(int *i) {
	*i = *i + 1;
}


int main(void)
{
	int i;

	i = 5;
	increase(&i);
	printf("i: %d\n", i);
	return (0);
}