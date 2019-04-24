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
		for (j = 0; j < n - i - 1; j += 2) {//bugs here, true: j += 1
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	
	//print result	
	char filename[16] = "result.csv";
	char buffer[128];
	//open file
	FILE *log = fopen(filename, "a");
	if (NULL == log) {
		printf("Error: File cannot be open/create \n");
		return 1;
	}
	sprintf(buffer, "%d,%d,%d,%d,%d\n", arr[0], arr[1],arr[2],arr[3],arr[4]);
	fwrite(buffer, sizeof(char), strlen(buffer), log);
	fclose(log);
	return 0;
	
}