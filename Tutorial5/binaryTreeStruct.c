#include <stdlib.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0

void insert(struct binary_tree_node **, int);
void traverse(struct binary_tree_node *);
void search (struct binary_tree_node **, int, struct binary_tree_node **, struct binary_tree_node **, int *);
void delete (struct binary_tree_node **, int);

struct binary_tree_node{
    struct binary_tree_node *left_child;
    struct binary_tree_node *right_child;
    int data;
};

int main(void){
    struct binary_tree_node *root;
    int i=0; 
    int content[] = {11, 9, 13, 8, 10, 12, 14, 15, 7};
    root = NULL;

    while (i <= 8){
        insert(&root, content[i]);
        i++;
    }

    traverse(root);
    printf("\n");

    delete (&root, 9);
    traverse(root);


}
void insert(struct binary_tree_node **node, int num){ //node based sorting 
    if (*node == NULL){
        *node = (struct binary_tree_node *) malloc (sizeof(struct binary_tree_node));
        (*node) -> left_child = NULL;
        (*node) -> right_child = NULL;
        (*node) -> data = num;
    }
    else{
        if (num < (*node) -> data){
            insert( &((*node) -> left_child), num);
        }else{
            insert(&((*node)-> right_child), num);
        }
    }
}

void traverse(struct binary_tree_node *node){
    if (node != NULL){
        traverse(node -> left_child);
        printf("%d\t", node -> data);
        traverse(node -> right_child);
    }
}

void search (struct binary_tree_node **root, int num, struct binary_tree_node ** parent, struct binary_tree_node **found_node, int *found_status){
    struct binary_tree_node *temp; 
    temp = *root;
    *found_status = FALSE;
    *parent = NULL;

    while (temp != NULL){
        if(temp -> data == num){
            *found_status = TRUE;
            *found_node = temp;
            return;
        }
        *parent = temp;
        if (temp -> data > num) {
            temp = temp -> left_child;
        }
        else{
            temp = temp -> right_child;
        }
    }
}

void delete (struct binary_tree_node **root, int num){
    int found;
    struct binary_tree_node *parent, *search_node, *next;

    if (*root == NULL){
        printf("tree is empty\n");
        return;
    }

    parent = search_node = NULL;
    search(root, num, &parent, &search_node, &found);

    if(found == FALSE){
        printf("Data not found\n");
        return; 
    }

    if(search_node -> left_child != NULL && search_node -> right_child != NULL ){ // this function doesn't do a return and that's important
        parent = search_node;
        next = search_node -> right_child;
        while (next -> left_child != NULL){
            parent = next; 
            next = next -> left_child;
        }
        search_node -> data = next -> data;
        search_node = next; 
        printf("new left node is %d\n", parent -> right_child -> data);
    }

    if (search_node -> left_child == NULL && search_node -> right_child == NULL){
        printf("called 2");
        if (parent -> right_child == search_node){
            parent -> right_child = NULL;
        }else{
            parent -> left_child = NULL;
        }
        free (search_node);
        return;
    }

    if (search_node -> left_child == NULL && search_node -> right_child !=NULL){
        printf("called 3");
        if (parent -> left_child == search_node){
            parent -> left_child = search_node -> right_child;
        }else{
            parent -> right_child =search_node -> right_child;
        }
        free(search_node);
        return;
    }

    if (search_node -> left_child != NULL && search_node -> right_child == NULL){
        printf("called 4");
        if (parent -> right_child == search_node){
            parent -> right_child = search_node -> left_child;
        }else{
            parent -> left_child = search_node -> left_child;
        }
        free (search_node);
        return; 
    }
}