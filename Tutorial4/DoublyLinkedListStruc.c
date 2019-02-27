#include <stdio.h>

int count (struct node *);
int display (struct node *);
void append (struct node **, int num);
void prepend (struct node **, int num);

struct node{
	int data;
	struct node *prev;
	struct node *next;
}; 

int count (struct node *list){
	int count = 0;
	while(list != NULL){
		list = list -> next;
		count++;
	}
	return count;
}

int display (struct node *list){
	while (list != NULL){
		printf("%2d\t", list -> data);
		list = list -> next; 
	}
	printf("\n");
}

void append (struct node **list, int num){
	struct node *temp, *current = *list;
	if(*list==NULL){
		*list = (struc node *) malloc(sizeof(struct node));
		(*list) -> prev = NULL; 
		(*list) -> data = num;
		(*list) -> next = NULL;
	}
	else{
		while(current  -> next != NULL){
			current = current -> next;
		}
		temp = (struc node *) malloc(sizeof(struc node));
		temp -> data = num;
		temp -> next = NULL;
		temp -> prev = current;
		current -> next = temp;
	}
}

void prepend (struct node **list, int num){
	struct node *temp;
	temp = (struct node *) malloc (sizeof(struct node));
	temp -> prev = NULL;
	temp -> data = num; 
	temp -> next = *list;
	(*list) -> prev =temp;
	*list = temp;
