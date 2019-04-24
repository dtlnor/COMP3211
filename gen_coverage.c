#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
	
	char coverageData[32] = "bugAlgo.c.gcov";
	char bugResultFile[32] = "bugAlgoResult.csv";
	char trueResultFile[32] = "trueAlgoResult.csv";
	char coverageResult[32] = "coverageResult.csv";
	char* bugResult = argv[1];
	char* trueResult = argv[2];

	FILE *log;
	FILE *gcovFile;
	char buffer[128];
	char buffer2[128];
	int i;
	
	//append bugAlgoFile.csv to bugAlgoResult.csv
	log = fopen(bugResultFile, "a");
	if (NULL == log) {
		printf("Error: File cannot be open/create \n");
		return 1;
	}
	sprintf(buffer, "%s\n", bugResult);
	fwrite(buffer, sizeof(char), strlen(buffer), log);
	
	fclose(log);
	
	//append bugAlgoFile.csv to trueAlgoResult.csv
	log = fopen(trueResultFile, "a");
	if (NULL == log) {
		printf("Error: File cannot be open/create \n");
		return 1;
	}
	sprintf(buffer, "%s\n", trueResult);
	fwrite(buffer, sizeof(char), strlen(buffer), log);
	
	fclose(log);
	

	//printf("bug: %s true: %s \n", argv[1], argv[2]);

	int resultSuccessful;
	//find if bug result is same as true result
	if (strcmp(bugResult, trueResult) == 0) {
		//printf("success");
		resultSuccessful = 0;
	}
	else {
		//printf("fail");
		resultSuccessful = 1;
	}
	
	

	//genarate (executable) line of code and coverage statement
	int lineOfCode = 0;
	int *statementCoverage;
	char line[128];

	//caculate line of code
	gcovFile = fopen(coverageData, "r");
	if (NULL == gcovFile) {
		printf("Error: File cannot be open \n");
		return 1;
	}

    while ( fgets ( line, sizeof line, gcovFile) != NULL ) { /* read a line */
		//printf("%s",line);
		if (line[8] != '-'){
			lineOfCode++;
		}
    }
	fclose(gcovFile);

	//calculate coverage statement
	gcovFile = fopen(coverageData, "r");
	if (NULL == gcovFile) {
		printf("Error: File cannot be open \n");
		return 1;
	}

	statementCoverage = malloc( lineOfCode * sizeof(int));
	lineOfCode = 0;

	while ( fgets ( line, sizeof line, gcovFile) != NULL) { /* read a line */
		//printf("%c:::%s", line[8], line);
		if (line[8] != '-') {
			lineOfCode++;
			if (line[8] == '#') {
				statementCoverage[lineOfCode - 1] = 0;
			}
			else {
				statementCoverage[lineOfCode - 1] = 1;
			}
		}
	}
	fclose(gcovFile);

	

	//output to coverageResult
	int numberOfLine = 0;
	if ((log = fopen(coverageResult, "r")) == NULL)
	{

		//File not found, no memory leak since 'file' == NULL
		//fclose(file) would cause an error

		log = fopen(coverageResult, "w");
		if (NULL == log) {
			printf("Error: File cannot be open/create \n");
			return 1;
		}

		sprintf(buffer, "bugAlgo");
		for (i = 0; i < lineOfCode; i++) {
			sprintf(buffer2, "%s,s%d", buffer, i + 1);
			sprintf(buffer, "%s", buffer2);
		}
		sprintf(buffer2, "%s,r\n", buffer);
		sprintf(buffer, "%s", buffer2);
		fwrite(buffer, sizeof(char), strlen(buffer), log);

		numberOfLine++;

		//printf(" here %s \n", buffer);
	}
	else
	{
		// file exists

		while (fgets(line, sizeof line, log) != NULL) { /* read a line */
			numberOfLine++;
		}

		fclose(log);
		log = fopen(coverageResult, "a");
		if (NULL == log) {
			printf("Error: File cannot be open/create \n");
			return 1;
		}

	}

	sprintf(buffer, "t%d", numberOfLine);
	for (i = 0; i < lineOfCode; i++) {
		sprintf(buffer2, "%s,%d", buffer, statementCoverage[i]);
		sprintf(buffer, "%s", buffer2);
	}
	sprintf(buffer2, "%s,%d\n", buffer, resultSuccessful);
	sprintf(buffer, "%s", buffer2);
	fwrite(buffer, sizeof(char), strlen(buffer), log);

	fclose(log);
	
	return 0;

}