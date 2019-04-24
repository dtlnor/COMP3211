#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int arr[argc - 1];
	int n = argc - 1;
	int i,j;
	int x=0;
	
	for (i = 0; i < n; i++) {
		arr[i] = atoi(argv[i+1]);
	}

	for (j = 0; j < n-1; j++){
		
		if (arr[j]>=arr[j+1])
		{			
			if (arr[j] >= x) x = arr[j+1]; //fault
		}			
		else{
			if (arr[j+1] >= x) x = arr[j+1];
		}
	}
	printf ("%d\n",x);
    
    return 0;
}