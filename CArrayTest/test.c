#include <stdio.h>
#include <stdlib.h>

int getSum(int p[], int n)
{
	int sum = 0;
	int i;

	for (i = 0; i < n; i++) sum += p[i];

	return sum;
}

void print(int p[], int n)
{
	int sum = 0;
	int i;

	for (i = 0; i < n; i++) printf("%d ", p[i]);
	printf("\n");
}

main()
{
	int *x;
	int i;
	int sum = 0;
	int n;

	printf("Type size of array : ");
	scanf("%d", &n);

	x = (int *)malloc(n*sizeof(int));

	for (i = 0; i < n; i++) {
		x[i] = rand() % 100;
	}

	sum = getSum(x, n);

	printf("sum = %d\n", sum);

	print(x, n);

	/*
	int x[100];
	int i;
	int sum = 0;
	int n;

	printf("Type size of array : ");
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		x[i] = rand() % 100;
	}

	sum = getSum(x, n);

	printf("sum = %d\n", sum);

	print(x, n);*/
}