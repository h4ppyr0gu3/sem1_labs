#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
	int x_val;
	int y_val;
} Coords;

int main(int argc, char const *argv[]) {
	char test[5];
	int points;

	printf("please enter the number of coordinates you would like to enter: ");
	scanf(" %19[^\n]", test);
	sscanf(test, "%d", &points);

	Coords coordinates;
	Coords coords[points];

	printf("\n");

	for (int i = 0; i < points; ++i) {
		printf("please enter the coordinates x and y seperated by a space (x y): ");
		scanf(" %19[^\n]", test);
		sscanf(test, "%d %d", &coords[i].x_val, &coords[i].y_val);
	}

	float perimeter = 0.0;

	for (int i = 0; i < points - 1; ++i) {
		int delta_x = coords[i + 1].x_val - coords[i].x_val;
		int delta_y = coords[i + 1].y_val - coords[i].y_val;
		perimeter += (sqrt(((delta_x*delta_x) + (delta_y*delta_y))));
	}

	int delta_x = coords[0].x_val - coords[points - 1].x_val;
	int delta_y = coords[0].y_val - coords[points - 1].y_val;

	perimeter += ( sqrt(  ((delta_x*delta_x) + (delta_y*delta_y))  ) );

	printf("\n");
	printf("perimeter = %f\n", perimeter);
	printf("\n");

	for (int i = 0; i < points; ++i) {
		printf("coordinate pair %d: (%d, %d)\n", i + 1, coords[i].x_val, coords[i].y_val);
	}


	return 0;
}