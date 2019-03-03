#include <stdio.h>
#include <stdlib.h>


struct DataItem* delete(struct DataItem*);
void display();
int hashCode(int );
void insert(int, int);

#define SIZE 10

struct DataItem{
    int data;
    int key;
};

struct DataItem *hashArray[SIZE];
struct DataItem *tempItem;
struct DataItem *item; 

void display(void){
    int i; 
    for (i=0; i<SIZE; i++){
        if (hashArray[i] != NULL){
            printf(" (%d,%d)", hashArray[i] -> key, hashArray[i] -> data);
        }else{
            printf(" ~,~ ");
        }
    }
    printf("\n");
}

int hashCode(int key){
    return key % SIZE;
}

void insert(int key, int data){
    struct DataItem *item = (struct DataItem*) malloc(sizeof(struct DataItem));
    item -> data = data;
    item -> key = key;

    int hashIndex = hashCode(key);
    while
}