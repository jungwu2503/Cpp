#include <stdio.h>
#include <string.h>

typedef struct _student {
	char *name;
	int grade;
} Student;

void print(Student *s, int n)
{
	int i;

	for (i = 0; i < n; i++) {
		printf("%10s %5d\n", s[i].name, s[i].grade);
	}
}

main()
{
	Student st[100];
	FILE *inFile;
	int n; // 라인수
	int i;

	inFile = fopen("data.txt", "r");
	n = 0;
	while (!feof(inFile)) {
		char name[BUFSIZ];
		int grade;

		fscanf(inFile, "%s %d", name, &grade);
		n++;
	}

	fclose(inFile);
	printf("size = %d\n", n);

	inFile = fopen("data.txt", "r");

	for (i = 0; i < n; i++) {
		char name[BUFSIZ]; //넉넉한 사이즈
		int grade;

		fscanf(inFile, "%s %d", &name[0], &grade);
		st[i].name = strdup(name);
		st[i].grade = grade;
	}

	print(&st[0], n);

	fclose(inFile);
}

/*
typedef struct _student {
	char name[10];
	int grade;
} Student;

void print(Student *s, int n)
{
	int i;

	for (i = 0; i < n; i++) {
		printf("%10s %5d\n", s[i].name, s[i].grade);
	}
}

main()
{
	Student st[100];
	FILE *inFile;
	int n; // 라인수
	int i;

	inFile = fopen("data.txt", "r");
	n = 0;
	while (!feof(inFile)) {
		char name[10];
		int grade;

		fscanf(inFile, "%s %d", name, &grade);
		n++;
	}

	fclose(inFile);
	printf("size = %d\n", n);

	inFile = fopen("data.txt", "r");

	for (i = 0; i < n; i++) {
		char name[10];
		int grade;

		fscanf(inFile, "%s %d", &name[0], &grade);
		strcpy(st[i].name, name);
		st[i].grade = grade;
	}

	print(&st[0], n);

	fclose(inFile);
}*/