#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
	
	char coverageData[32] = "bugAlgo.c.gcov";
	char bugResultFile[32] = "bugAlgoResult.csv";
	char trueResultFile[32] = "trueAlgoResult.csv";
	char c;
	
	char* bugResult = argv[1];
	char* trueResult = argv[2];
	FILE *log;
	
	char buffer[128];
	
	//append bugAlgoFile.csv to bugAlgoResult.csv
	log = fopen(bugResultFile, "a");
	if (NULL == log) {
		log = fopen(bugResultFile, "w");
	}
	sprintf(buffer, "%s\n", bugResult);
	fwrite(buffer, sizeof(char), strlen(buffer), log);
	
	fclose(log);
	
	//append bugAlgoFile.csv to trueAlgoResult.csv
	log = fopen(trueResultFile, "a");
	if (NULL == log) {
		log = fopen(trueResultFile, "w");
	}
	sprintf(buffer, "%s\n", trueResult);
	fwrite(buffer, sizeof(char), strlen(buffer), log);
	
	fclose(log);
	

	printf("bug: %s true: %s \n", argv[1], argv[2]);

	//find if bug result is same as true result
	if (strcmp(bugResult, trueResult) == 0) {
		printf("true");

	}
	else {
		printf("false");
	}
	
	
	log = fopen(coverageData, "r");
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