#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int factorial(int a) {
	int value = 1;
	for (int i = 0; i < a; ++i) {
		value = value * (i + 1);
	}
	return value;
}

int main(int argc, char *argv[]) {
	for (int i = 0; i < argc; ++i) {
		printf("Parameter %d: %s\n", i, argv[i]);
	}

	if (argc < 3) {
		printf("please enter all necessary values");
		return 1;
	}

	double x0 = (atoi(argv[1]) * 1.0);

	if (x0 > 2 || x0 <= 0) {
		printf("please provide a valid x0\n0 < x0 <=2");
	}

	printf("x0 = %s\nN = %s\n", argv[1], argv[2]);

	double a = log(x0);

	int n = atoi(argv[2]);

	if (n < 0) {
		printf("please enter a valid value of N\nN > 0\n");
	}

	printf("\nmath.h ln(%s) = %f \n", argv[1], a);

	double summation = 0.0;
	double sum = 0.0;
	double placeholder;

	for (int i = 0; i < n; ++i) {
		int n_val = i + 1;
		double pow_n_plus_1 = pow(-1, (n_val + 1));
		double x0_minus_1_pow_n = pow((x0 - 1), n_val);
		double fraction = (pow_n_plus_1)/ n_val;
		double total = fraction  * x0_minus_1_pow_n;

		sum = total + sum;
	}

	printf("\ntaylor ln(%s) = %f\n", argv[1], sum);

	double epsilon = sum - a;

	printf("\nepsilon = %f \n ", epsilon);
}