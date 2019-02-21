#include <stdio.h>
#define MAX 5; 

void init_stack(struct stack *);
void push (struct stack *, int item);
void pop (struct stack *);

struct stack{
	int array[MAX];
	int top;
}

void init_stack(struct stack *s){
	s->top =-1;
}

int main(void){
	struct stack s;
	init_stack

void push(struct stack *s, int item){
	if (s-> top == MAX-1){
		printf("Stack is full. Couldn't push '%d' onto stack\n", item);
		return;
	}
	s->top++;
	s->array[s->top] = item;
	
void *pop (struct stack *s){
	if (s->top == -1){
		printf("Stack is empty\n");
		return null;
	}
	data = &s->array[s->top];
	s->top--;
	return data;
}
	
	
void enqueue (int *arr, int item, int *pfront, int *prear){
	if(*prear == MAX -1){
		printf("Queue is full\n");
		return; 
	}
	else{
		printf("Enqueuing: %d\n", item);
		(*prear)++;
		arr[*prear] = item;
		
		if(*pfront == -1)
			*pfront =0;
	}
}