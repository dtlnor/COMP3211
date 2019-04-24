#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	
	char coverageData[32] = "bugAlgo.c.gcov";
	char bugResult[32] = "bugAlgoResult.csv";
	char trueResult[32] = "trueAlgoResult.csv";
	char c;
	
	FILE *log = fopen(coverageData, "r");
	if (NULL == log) {
		printf("Error: File cannot be open \n");
		return 1;
	}
	
	int i = 0;

    char line[128];
    while ( fgets ( line, sizeof line, log ) != NULL ) { /* read a line */
		//printf("%s",line);
		
		if (line[8] != '-'){
			i++;
		}
	
    }

	printf("%d\n\n", i);

	fclose(log);
	return 0;

}