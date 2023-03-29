#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

int getSum(int **p, int row, int col) 
{
	int sum, i, j;
	sum = 0;

	for (i = 0; i < row; i++) 
		for (j = 0; j < col; j++)
			sum += p[i][j];

	return sum;
}

void print(int **p, int row, int col) 
{
	int i, j;

	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			printf("%5d ", p[i][j]);
		}
		printf("\n");
	}		
	printf("\n");
}

int **allocInt(int row, int col) 
{
	int **p;
	int i;

	p = (int **)malloc(row*sizeof(int*));

	for (i = 0; i < row; i++) {
		p[i] = (int *)malloc(col*sizeof(int));
	}

	return p;
}

main()
{
	int **x;
	int i, j, sum;
	
	int n, m;

	printf("Type row and col in one line : ");
	scanf("%d %d", &n, &m);

	x = allocInt(n, m);

	for (i = 0; i < n; i++) 
		for (j = 0; j < m; j++)
			x[i][j] = rand() % 100;

	sum = getSum(x,n,m);
	printf("sum = %d\n", sum);
	print(x,n,m);
}

/*int getSum(int p[], int row, int col) 
{
	int sum, i, j;
	sum = 0;

	for (i = 0; i < row; i++) 
		for (j = 0; j < col; j++)
			sum += p[i * col +j]; //p[i][j]

	return sum;
}

void print(int p[], int row, int col) 
{
	int i, j;

	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			printf("%5d ", p[i * col +j]);
		}
		printf("\n");
	}		
	printf("\n");
}

main()
{
	int *x;
	int i, j, sum;
	
	int n, m;

	printf("Type row and col in one line : ");
	scanf("%d %d", &n, &m);

	x = (int *)malloc(n*m*sizeof(int));

	for (i = 0; i < n; i++) 
		for (j = 0; j < m; j++)
			x[i*m+j] = rand() % 100;

	sum = getSum(x,n,m);
	printf("sum = %d\n", sum);
	print(x,n,m);
} */

/*
int getSum(int p[], int row, int col) 
{
	int sum, i, j;
	sum = 0;

	for (i = 0; i < row; i++) 
		for (j = 0; j < col; j++)
			sum += p[i * col +j]; //p[i][j]

	return sum;
}

void print(int p[], int row, int col) 
{
	int i, j;

	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			printf("%5d ", p[i * col +j]);
		}
		printf("\n");
	}		
	printf("\n");
}

main()
{
	//int x[3][4];
	int x[10][10];
	int i, j, sum;
	
	int n, m;

	printf("Type row and col in one line : ");
	scanf("%d %d", &n, &m);

	for (i = 0; i < n; i++) 
		for (j = 0; j < m; j++)
			x[i][j] = rand() % 100;

	sum = getSum((int *)x,n,m);
	printf("sum = %d\n", sum);
	print((int *)x,n,m);	

	//for (i = 0; i < 3; i++) 
	//	for (j = 0; j < 4; j++)
	//		x[i][j] = rand() % 100;

	//sum = getSum((int *)x,3,4);
	//printf("sum = %d\n", sum);
	//print((int *)x,3,4);
}
*/