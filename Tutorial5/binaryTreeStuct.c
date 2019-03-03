#include <stdlib.h>
#include <stdio.h>

struct binary_tree_node{
    struct binary_tree_node *left_child;
    struct binary_tree_node *right_child;
    int data;
};

void insert(struct binary_tree_node **node, int num){
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