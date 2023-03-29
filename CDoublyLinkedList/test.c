#include <stdio.h>
#include <malloc.h>
#include "LinkedList.h"

//doubly LinkedLIst -> Singly LinkedList 단점 보완(add, traverse 역순)

main()
{
	LinkedList list1;
	LinkedList list2;
	LinkedList *list3;
	int *arr;
	int i;

	initList(&list1);
	initList(&list2);

	printf("list1 = ");
	print(&list1);
	printf("list2 = ");
	print(&list2);

	add(&list1, 10);
	add(&list1, 20);
	add(&list1, 30);
	add(&list1, 40);

	add(&list2, 100);
	add(&list2, 200);

	printf("list1 = ");
	print(&list1);
	printf("list2 = ");
	print(&list2);

	//addAt(&list1, 0, 7);
	//print(&list1);

	addAllAt(&list1, &list2, 5);
	printf("list1 = ");
	print(&list1);

	//clear(&list1);
	//print(&list1);

	list3 = clone(&list1);
	printf("list3 = ");
	print(list3);

	//printf("%d\n", contains(&list1,110));
	//printf("%d\n", get(&list1,7));
	//printf("%d\n", getFirst(&list1));
	//printf("%d\n", getLast(&list1));
	//printf("%d\n", indexOf(&list1, 50));
	//printf("%d\n", lastIndexOf(&list1, 7));

	set(&list1, 2, 77);
	printf("list1 = ");
	print(&list1);

	removeData(&list1, 77);
	printf("list1 = ");
	print(&list1);
	
	removeAt(&list1, 1); 
	printf("list1 = ");
	print(&list1);

	arr = toArray(&list1);
	printf("[ ");
	for (i = 0; i < size(&list1); i++) {
		printf("%d ", arr[i]);
	}
	printf("]\n");

	disposeList(&list1);
	/*
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
	}*/
}
