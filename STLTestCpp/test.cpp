#include <iostream>
using namespace std;
#include <vector>
#include <stack>
#include <list>

template <class Type>
ostream& operator<<(ostream &outs, list<Type> &v) 
{
	outs << "[";
	list<Type>::iterator it = v.begin();
	while (it != v.end()) {
		Type data = *it;
		outs << data;
		it++;
		if (it != v.end()) outs << " ";
	}

	/*for (int i = 0; i < v.size(); i++)
	{
		outs << v[i];
		if (i < v.size()-1) outs << " ";
	}*/
	outs << "]";

	return outs;
}

template <class Type>
ostream& operator<<(ostream &outs, vector<Type> &v) 
{
	outs << "[";
	for (int i = 0; i < v.size(); i++)
	{
		outs << v.at(i);
		if (i < v.size()-1) outs << " ";
	}
	outs << "]";
	return outs;
}

void main()
{
	vector<int> v1;
	stack<int> x1;
	list<int> l1;

	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_front(40);
	l1.push_front(50);

	cout << l1 << endl;

	x1.push(10);
	x1.push(20);
	x1.push(30);

	//cout << x1 << endl;

	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);

	cout << v1 << endl;
	/*for (int x : v1) {
		cout << x << " ";
	}*/
}