#include <stdio.h>

#define MAX_ITER 20

int main(int argc, char *argv[])
{
	float xn = 1.0 / 3.0;
	float xnp = 1.0;

	for (int i = 0; i < MAX_ITER; ++i)
	{
		float xnn = (13.0 * xn - 4.0 * xnp) / 3.0;
		printf("x_%d = %.16f\n", i + 2, xnn);

		xnp = xn;
		xn = xnn;
	}

	return 0;
}