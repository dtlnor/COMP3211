#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#define randomSize 10
#define testcaseSize 4

int main(){

	char filename[16] = "testcase.csv";

	//open file
	FILE *log = fopen(filename, "w");
	if (NULL == log) {
		printf("Error: File cannot be open/create \n");
		return 1;
	}

	char buffer[128];

	int ran[5];
	int i,j;
	srand(time(NULL));

	for (i = 0; i < testcaseSize; i++) {
		for (j = 0; j < 5; j++) {
			ran[j] = (rand() % randomSize) + 1;
		}
		sprintf(buffer, "%d,%d,%d,%d,%d\n", ran[0],ran[1],ran[2],ran[3],ran[4]);
		fwrite(buffer, sizeof(char), strlen(buffer), log);
	}

	fclose(log);

	return 0;

}