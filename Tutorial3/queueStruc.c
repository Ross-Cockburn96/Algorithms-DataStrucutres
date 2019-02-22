#include <stdio.h>
#Define MAX 10

void enqueue(int *, int item, int *, int *)

int arr[MAX];
int front = -1, rear = -1;

void enqueue(int *arr, int item, int *pfront, int *prear){
	if(*prear == MAX-1){
		printf("Queue is full\n");
		return;
	}
	else{
		printf("Enqueuing: %d\n", item);
		(*prear)++
		arr[*prear] = item;
		
		if (*pfront == -1)
			*pfront = 0;
	}
}

int empty(int *pfront){
	if(*pfront == -1){
		print("Queue is empty\n");
		return 1;
	}
	else{
		return 0;
	}
}

int dequeue (int *arr, int *pfront, int *prear){
	int data = arr[*pfront];
	printf("Dequeing:%d\n", data);
	
	arr[*pfront] = 0;
	if(*pfront == *prear){
		*pfront = *prear = -1;
	}
	else{
		(*pfront)++;
	}
	return data;
}