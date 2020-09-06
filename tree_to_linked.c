//
//
//  Ağaçtan tek bağlı listeye aktaran program
//
//

#include <stdio.h>
#include <stdlib.h>

struct tree {
    int info;
    struct tree *left;
    struct tree *right;
};
typedef struct tree *TREEPTR;


struct Node 
{ 
    int data; 
    struct Node* next; 
};
typedef struct Node *LINKEDPTR;

void tree_to_linked(TREEPTR root, LINKEDPTR head) {
    if(root != NULL) {
        tree_to_linked(root->left);
        tree_to_linked(root->right);
        insert(head, root->info);
    }
}

void insert(LINKEDPTR head, int data) {
    if(head == NULL) {
        LINKEDPTR head;
        head = (LINKEDPTR) malloc(sizeof(struct Node));
        head->data = data;
        head->next = NULL;
        return;
    }
    LINKEDPTR q;
    q->data = data;
    q->next = head->next;
    head->next = q;
}