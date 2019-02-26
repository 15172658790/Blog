#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, int len)
{
	int i;
	for (i = 0; i < len; i++) {
		printf(" %.2x", start[i]);
	}
	printf("\n");
}

void show_int(int x)
{
	show_bytes((byte_pointer)&x, sizeof(int));
}

void show_float(float x)
{
	show_bytes((byte_pointer)&x, sizeof(float));
}

void show_pointer(void *x)
{
	show_bytes((byte_pointer)&x, sizeof(void *));
}

int main(void)
{
	printf("the size of short int is: %d\n", sizeof(short int));
	printf("the size of float is: %d\n", sizeof(float));
	printf("the size of double is: %d\n", sizeof(double));

	short int x = 12345;
	short int mx = -x;
	show_bytes((byte_pointer)&x, sizeof(short int));
	show_bytes((byte_pointer)&mx, sizeof(short int));

	float f = 0.375;
	float mf = -f;
	show_bytes((byte_pointer)&f, sizeof(float));
	show_bytes((byte_pointer)&mf, sizeof(float));
}