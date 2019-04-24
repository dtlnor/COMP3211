#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
	
	int arr[argc - 1];
	int n = argc - 1;
	int i, j;
	int temp;
	
	for (i = 0; i < n; i++) {
		arr[i] = atoi(argv[i+1]);
	}
	
	//printf("%d %d %d %d %d\n", arr[0], arr[1],arr[2],arr[3],arr[4]);
	
	for (i = 0; i < n - 1; i += 1) {
		for (j = 0; j < n - i - 1; j += 1) {//here, false: j += 2
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	
	//print result	
	printf("%d,%d,%d,%d,%d", arr[0], arr[1],arr[2],arr[3],arr[4]);
	
	return 0;
	
}