#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int arr[argc - 1];
	int n = argc - 1;
	int i;
	int output[argc - 1];
	
	for (i = 0; i < n; i++) {
		arr[i] = atoi(argv[i+1]);
		output[i] = 0;
	}


	if ( arr[0] % 3 == 0 ){ //even //fault
		output[0] = 0;
	} else { //odd
		output[0] = 1;
	}
	
	if ( arr[1] % 2 == 0 ){ //even
		output[1] = 0;
	} else { //odd
		output[1] = 1;
	}
	
	if ( arr[2] % 2 == 0 ){ //even
		output[2] = 0;
	} else { //odd
		output[2] = 1;
	}
	
	if ( arr[3] % 2 == 0 ){ //even
		output[3] = 0;
	} else { //odd
		output[3] = 1;
	}
	
	if ( arr[4] % 2 == 0 ){ //even
		output[4] = 0;
	} else { //odd
		output[4] = 1;
	}
	
	
	printf ("%d,%d,%d,%d,%d\n",output[0], output[1],output[2],output[3],output[4]);
    
    return 0;
}