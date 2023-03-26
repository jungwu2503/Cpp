#include <stdio.h>

void add(int x, int y)
{
	printf("%d + %d = %d\n", x, y, x+y);
}

void subtract(int x, int y)
{
	printf("%d - %d = %d\n", x, y, x-y);
}

void multiply(int x, int y)
{
	printf("%d * %d = %d\n", x, y, x*y);
}

void divide(int x, int y)
{
	printf("%d / %d = %d\n", x, y, x/y);
}

main()
{
	void (*f[4])(int,int);

	f[0] = add;
	f[1] = subtract;
	f[2] = multiply;
	f[3] = divide;

	while (1) {
		int n;
		int x, y;

		printf("What do you want? <1, 2, 3, 4>\n");
		scanf("%d", &n);
		printf("Type two data\n");
		scanf("%d %d", &x, &y);
		(*f[n-1])(x, y);
	}

	/*
	void (*f)(int,int);

	f = add;
	(*f)(30,40);

	f = subtract;
	(*f)(30,40);*/
}