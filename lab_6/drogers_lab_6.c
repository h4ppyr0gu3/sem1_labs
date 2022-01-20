#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[]) {
	
	int rows, columns, start, end, error;

	do {
		error = 0;
		printf("Give number of rows: ");
		scanf(" %d", &rows);
		printf("Give number of columns: ");
		scanf(" %d", &columns); 
		if ( rows < 1 || columns < 1) {
			error = 1;
			printf("please enter positive integer for rows and columns\n");
		}	
	} while(error == 1);

	printf("\n");
	
	do {
		error = 0;
		printf("Give starting value: ");
		scanf(" %d", &start);
		printf("Give ending value: ");
		scanf(" %d", &end);
		if ( start >= end || start < 1) {
			error = 1;
			printf("please enter positive values and a start value less than end value\n");
		}	
	} while(error == 1);

	printf("\n");

	srand(time(NULL));

	int array[rows][columns];
	int* pointer_array = &array[0][0];

	for (int i = 0; i < rows * columns; ++i) {
		if (i % (columns) == 0 && i != 0 ) 
			printf("\n");
		*(pointer_array + i) = start + (rand() % (end - start));
		printf("%d ", *(pointer_array + i));
	}

	printf("\n\n");

	int column_array[columns], row_array[rows];
	int greatest_column = 0, greatest_row = 0, max_column_index, max_row_index;

	int* row_array_pointer = &row_array[0];
	int* column_array_pointer = &column_array[0];

	for (int i = 0; i < rows; ++i) {
		*(row_array_pointer + i) = 0;
	}

	for (int i = 0; i < columns; ++i) {
		*(column_array_pointer + i) = 0;
	}

	int count = 0;

	for (int i = 0; i < rows * columns; ++i) {
		if (i % columns == 0 && i != 0)
			count++;
		*(column_array_pointer + (i % columns)) += *(pointer_array + i);
		*(row_array_pointer + count) += *(pointer_array + i);
	} 

	for (int i = 0; i < columns; ++i) {
		if(greatest_column < *(column_array_pointer + i)) {
			greatest_column = *(column_array_pointer + i);
		}
	} 

	for (int i = 0; i < rows; ++i) {
		if(greatest_row < *(row_array_pointer + i)) {
			greatest_row = *(row_array_pointer + i);
		}
	} 

	for (int i = 0; i < rows; ++i) {
		if(greatest_row == *(row_array_pointer + i)) {
			max_row_index = i + 1;
		}
	}

	for (int i = 0; i < columns; ++i) {
		if(greatest_column == *(column_array_pointer + i)) {
			max_column_index = i + 1;
		}
	}


	printf("Max column: %d\n", max_column_index);
	printf("Max row: %d\n", max_row_index);

	return 0;
}