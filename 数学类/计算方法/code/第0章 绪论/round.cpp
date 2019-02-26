#include <stdio.h>

int main(void)
{
	double res1 = (3.14 + 1.0E20) - 1.0E20;
	double res2 = 3.14 + (1.0E20 - 1.0E20);
	printf("%e %e\n", res1, res2);
}