#include <stdio.h>

int main() {
	float f;
	float dec;
	int i;

	f = 14.257;
	i = (int)f;
	dec = f - i;
	printf("f: %f, i: %d, res: %d", f, i, (int)(-2147483648 * -1));
	return 0;
}
