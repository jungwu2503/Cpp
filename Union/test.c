#include <stdio.h>
#include <malloc.h>

void print(int *x)
{
	int i;
	if (*x == 1) {
		x++;
		for (i = 0; i < 10; i++) printf("%d ", x[i]);
	} else if (*x == 2) {
		double *p;
		x++;
		p = (double *)x;
		for (i = 0; i < 10; i++) printf("%f ", p[i]);
	} else if (*x == 3) {
		char *c;
		x++;
		c = (char *)x;
		for (i = 0; i < 10; i++) printf("%c ", c[i]);
	}
	printf("\n");
}

main()
{
	int *p;
	double *q;
	char *r;
	int i;

	p = (int *)malloc(sizeof(int)+10*sizeof(int));
	*p = 1;
	for (i = 0; i < 10; i++) {
		p[i+1] = 10+i;
	}
	print(p);

	p = (int *)malloc(sizeof(int)+10*sizeof(double));
	*p = 2;
	q = (double *)(p + 1);
	for (i = 0; i < 10; i++) {
		q[i] = 23.5*i;
	}
	print(p);

	p = (int *)malloc(sizeof(int)+10*sizeof(char));
	*p = 3;
	r = (char *)(p + 1);
	for (i = 0; i < 10; i++) {
		r[i] = 'c'+i;
	}
	print(p);
}

/*
typedef struct _variant_data { //declaration
	int type;
	union {
		int x[4];
		double y[4];
		char z[4];
	} data;
} VariantData;

void print(VariantData *p) 
{
	int i;
	switch (p->type) {
		case 1: {
			for (i = 0; i < 10; i++) {
				printf("%d ", p->data.x[i]);
			}
			break;
		}
		case 2: {
			for (i = 0; i < 10; i++) {
				printf("%f ", p->data.y[i]);
			}
			break;
		}
		case 3: {
			for (i = 0; i < 10; i++) {
				printf("%c ", p->data.z[i]);
			}
			break;
		}
		printf("\n");
	}
}

main() 
{
	VariantData a; // definition
	VariantData b;

	a.type = 1;
	a.data.x[0] = 50;
	a.data.x[1] = 60;
	a.data.x[2] = 70;
	a.data.x[3] = 80;
	print(&a);

	b.type = 2;
	b.data.y[0] = 34.51;
	b.data.y[1] = 34.52;
	b.data.y[2] = 34.53;
	b.data.y[3] = 34.54;
	print(&b);

	a.type = 3;
	a.data.z[0] = 'a';
	a.data.z[1] = 'b';
	a.data.z[2] = 'c';
	a.data.z[3] = 'd';
	print(&a);
}
*/
/*
typedef struct _variant_data { //declaration
	int type;
	union {
		int x;
		double y;
		char z;
	} data;
} VariantData;

void print(VariantData *p) 
{
	switch (p->type) {
		case 1: {
			printf("%d\n", p->data.x);
			break;
		}
		case 2: {
			printf("%f\n", p->data.y);
			break;
		}
		case 3: {
			printf("%c\n", p->data.z);
			break;
		}
	}
}

main() 
{
	VariantData a; // definition
	VariantData b;

	a.type = 1;
	a.data.x = 50;
	print(&a);

	b.type = 2;
	b.data.y = 34.51;
	print(&b);

	a.type = 3;
	a.data.z = 'a';
	print(&a);
}
*/
/*
void print(int *x)
{
	if (*x == 1) {
		x++;
		printf("%d\n", *x);
	} else if (*x == 2) {
		double *p;
		x++;
		p = (double *)x;
		printf("%f\n", *p);
	} else if (*x == 3) {
		char *c;
		x++;
		c = (char *)x;
		printf("%c\n", *c);
	}
}

main()
{
	int *p;
	double *q;
	char *r;

	p = (int *)malloc(sizeof(int)+sizeof(int));
	*p = 1;
	p[1] = 10;
	print(p);

	p = (int *)malloc(sizeof(int)+sizeof(double));
	*p = 2;
	q = (double *)(p + 1);
	*q = 23.14;
	print(p);

	p = (int *)malloc(sizeof(int)+sizeof(char));
	*p = 3;
	r = (char *)(p + 1);
	*r = 'c';
	print(p);
}
*/