#include <iostream>
using namespace std;

template <class T>
T add(T a, T b) 
{
	return a + b;
}

void main() 
{
	int x;
	double y;

	x = add(10, 20);
	cout << x << endl;

	y = add(34.5, 23.8);
	cout << y << endl;
}

/*
//int add(int a, int b) 
//{
//	return a + b;
//}
//
//int add(int a, int b, int c) 
//{
//	return a + b + c;
//}

// default argument - 부재 인수
int add(int a, int b, int c = 0, int d = 0) 
{
	return a + b + c + d;
}

void main()
{
	int x = 0;

	x = add(10, 20);
	cout << x << endl;

	x = add(10, 20, 30);
	cout << x << endl;

	x = add(10, 20, 30, 40);
	cout << x << endl;
}
*/