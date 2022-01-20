#include <stdio.h>
#include <stdlib.h>

int iterative_func(int a, int n) {
	int value = 1;
	for (int i = 1; i <= n; ++i) {
		value = value * a;
		printf("%d ^ %d = %d\n", a, i, value);
	}
	return value;
}

int recursive_func(int a, int n) {
	int value;
	if (n > 1) {
		value = a * recursive_func(a, --n);
		return value;
	}
}

int main() {
	int a, n, iterative, recursive;
	printf("please enter a value for A: ");
	scanf("%d", &a);
	printf("please enter a value for N: ");
	scanf("%d", &n);
	printf("\n");

	iterative = iterative_func(a, n);
	recursive = recursive_func(a, n);

	printf("\niterative(a^n) = %d", iterative);
	printf("\nrecursive(a^n) = %d", recursive);
	printf("\n");
}