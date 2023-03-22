#include <stdio.h>
#include <malloc.h>
#include "LinkedList.h"

main()
{
	LinkedList list1;
	LinkedList list2;
	int *arr;
	int i;

	initList(&list1);
	initList(&list2);

	add(&list1, 10);
	add(&list1, 20);
	add(&list1, 30);
	add(&list1, 30);
	add(&list1, 30);
	add(&list1, 40);
	add(&list1, 50);

	add(&list2, 100);
	add(&list2, 200);
	add(&list2, 300);

	printf("get 0 %d\n", get(&list1, 0));
	printf("getFirst %d\n", getFirst(&list1));
	printf("getLast %d\n", getLast(&list1));
	printf("list1 = ");
	print(&list1);

	printf("list2 = ");
	print(&list2);

	//printf("%d\n", get(&list1, 0));
	//printf("%d\n", element(&list1));
	//printf("%d\n", getFirst(&list1));
	//printf("%d\n", getLast(&list1));
	printf("%d\n", lastIndexOf(&list1, 30));
	
	set(&list1, 3, 700);

	//removeAt(&list1, 2);
	//removeAt(&list1, 0);
	removeData(&list1, 700);
	
	printf("list1 = ");
	print(&list1);

	arr = toArray(&list1);
	for (i = 0; i < size(&list1); i++) {
		printf("%d ", arr[i]);
	}

	/*LinkedList list1;
	LinkedList list2;
	LinkedList *copied;

	initList(&list1);
	initList(&list2);

	add(&list1, 10);
	add(&list1, 20);
	add(&list1, 30);
	add(&list1, 40);
	add(&list1, 50);

	printf("list1 = ");
	print(&list1);

	add(&list2, 100);
	add(&list2, 200);
	add(&list2, 300);

	printf("list2 = ");
	print(&list2);

	//addAllAt(&list1, &list2, 0);
	addAllAt(&list1, &list2, 2);
	//addAllAt(&list1, &list2, 10);

	printf("list1 = ");
	print(&list1);

	copied = clone(&list1);
	printf("copied = ");
	print(copied);

	printf("%s\n", contains(&list1, 300));

	printf("%d\n", get(&list1, 7));

	printf("%d\n", indexOf(&list1, 50));

	clear(&list1);
	printf("list1 = ");
	print(&list1);*/

	/*LinkedList list;
	int n;

	initList(&list);

	addAt(&list, 0, 5);

	addFirst(&list, 300);

	add(&list, 10);
	add(&list, 20);
	add(&list, 30);

	addFirst(&list, 100);
	addFirst(&list, 200);

	addLast(&list, 1000);
	addLast(&list, 2000);

	addAt(&list, 2, 1);
	addAt(&list, 0, 2);
	addAt(&list, 50, 3);
	printf("%d=====\n", size(&list));
	print(&list);
	addAt(&list, 11, 5);

	print(&list);

	n = size(&list);
	printf("%d\n", n);*/
}
