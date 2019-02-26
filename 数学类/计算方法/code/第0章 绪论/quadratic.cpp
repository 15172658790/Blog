#include <stdio.h>
#include <math.h>

template <typename T> int sgn(T val) {
	return (T(0) < val) - (val < T(0));
}

void find_root(double a, double b, double c, double &x1, double &x2)
{
	x1 = (-b - sqrt(b*b - 4.0*a*c)) / (2.0*a);
	x2 = (-b + sqrt(b*b - 4.0*a*c)) / (2.0*a);
}

void find_root_new(double a, double b, double c, double &x1, double &x2)
{
	x1 = (-b - sgn(b) * sqrt(b*b - 4.0*a*c)) / (2.0*a);
	x2 = c / (a * x1);
}

int main(int argc, char *argv[])
{
	double a = 1.0;
	double b = pow(9.0, 12.0);
	double c = -3.0;

	double x1, x2;
	find_root(a, b, c, x1, x2);
	printf("The solutions of quadratic euqation are: %.16f, %.16f\n", x1, x2);

	find_root_new(a, b, c, x1, x2);
	printf("The solutions of quadratic euqation are: %.16f, %.16f\n", x1, x2);

	return 0;
}