#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble_sort(int *array) {
	int store;
	for (int i = 0; i < 30; ++i)	{
		for (int j = 0; j < 30; ++j) {
			if ( j > i) {
				if(array[i] > array[j]) {
					store = array[i];
					array[i] = array[j];
					array[j] = store;
				}
			}
		}
	}
}

double sum(int *array) {
	double sum = 0.0;
	for (int j = 0; j < 30; ++j) {
		sum = sum + array[j];
	}
	return sum;
}

int main(int argc, char *argv[]) {
	if ( argc != 3 ) {
		printf("please enter all necessary values");
		return 1;
	}

	for (int i = 0; i < argc; ++i) {
		printf("Parameter %d: %s\n", i, argv[i]);
	}

	int larger_val, smaller_val;
	int array[31];
	int *array_ptr = array;

	if (atoi(argv[1]) > atoi(argv[2])) {
		larger_val = atoi(argv[1]);
		smaller_val = atoi(argv[2]);
	} else {
		larger_val = atoi(argv[2]);
		smaller_val = atoi(argv[1]);
	}

	srand(time(NULL));

	printf("\n");
	printf("pseudo random: ");

	for (int i = 0; i < 30; ++i) {
		array_ptr[i] = (rand() % (larger_val - smaller_val)) + smaller_val;
		printf("%d ", array_ptr[i]);
	}

	bubble_sort(array_ptr);

	printf("\nmin_value: %d \n", array_ptr[0]);
	printf("max_value: %d \n", array_ptr[29]);
	double mean = sum(array_ptr) / 30;
	printf("mean_value: %f \n", mean);

	printf("bubble sorted: ");

	for (int i = 0; i < 30; ++i) {
		printf("%d ", array_ptr[i]);
	}

	printf("\nsums of neighbour: ");

	for (int i = 0; i < 29; ++i) {
		printf("%d ", array_ptr[i] + array_ptr [i + 1]);
	}
	printf("\n");
}
