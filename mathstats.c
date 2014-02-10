/* Statistics - computes the mean and stand dev of an array of command line passed arguments using pointers */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void extrema(float *arr, int arr_size, float *mean, float *stdev);

int main(int argc, char **argv){

	float sum, y;
	/*this is to set aside memory for my array */	
	float * array = (float *) malloc( ( argc - 1 ) * sizeof(float) );

	int i;
	y = 0;
	sum = 0;
	for(i = 1; i < argc; i++){
		*(array+(i-1)) = atof(argv[i]);
		sum += *(array+(i-1));
	}
/*built the sum here to pass*/
	extrema(array, argc-1, &sum, &y);
	printf("Mean : %.2f\n", sum);
	printf("Standard Deviation : %.2f\n", y);
	free(array);

return 0;
}

void extrema(float * arr, int arr_size, float *mean, float *stdev){
	int j;
	float y = 0;
	*mean = *mean/arr_size;;
	for(j = 0; j<(arr_size); j++){
		y += (*(arr+j)-*mean)*(*(arr+j)-*mean);
	}
	y = y/(arr_size);	
	*stdev = sqrt(y);
}

