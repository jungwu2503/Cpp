#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct _alcohol {
	char *name;
	int ABV; //alcohol by volumn
} Alcohol;

void print(Alcohol *al, int n) {
	int i;
	for (i = 0; i < n; i++) printf("%10s %5d\n", al[i].name, al[i].ABV);
}

main() 
{
	Alcohol *al;
	FILE *inFile;
	int lineCount;
	int i;

	fopen_s(&inFile, "alcohol.txt", "r");
	lineCount = 0;
	while (!feof(inFile)) {
		char name[BUFSIZ];
		int ABV;

		fscanf_s(inFile, "%s %d", name, BUFSIZ, &ABV);
		lineCount++;
	}

	fclose(inFile);
	printf("Line count = %d\n", lineCount);

	al = (Alcohol *)malloc(sizeof(Alcohol)*lineCount);

	fopen_s(&inFile, "alcohol.txt", "r");

	for (i = 0; i < lineCount; i++) {
		char name[BUFSIZ];
		int ABV;

		fscanf_s(inFile, "%s %d", name, BUFSIZ, &ABV);
		al[i].name = _strdup(name);
		al[i].ABV = ABV;
	}

	print(al, lineCount);
	fclose(inFile);
}