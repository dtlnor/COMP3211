#include <stdio.h>
#include <stdlib.h>

// Driver program to test above functions 
int main()
{
	int arr[] = {5,4,3,2,1};
	int n = 5;
	int i, j;
	int temp;
	
	

	//scanf("%d %d %d %d %d", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4]);

	for (i = 0; i < n - 1; i += 1) { 
		for (j = 0; j < n - i - 1; j += 2) { //bugs here, true: j += 1
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}

	//out put sorted arr
	//for (i = 0; i < n; i++)
	//	printf("%d ", arr[i]);

	return 0;
}
