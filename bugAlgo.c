#include <stdio.h>
#include <stdlib.h>
int main(){
	int arr[] = {5,4,3,2,1};
	int n = 5;
	int i, j;
	int temp;
	for (i = 0; i < n - 1; i += 1)
		for (j = 0; j < n - i - 1; j += 2)//bugs here, true: j += 1
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
	return 0;
}