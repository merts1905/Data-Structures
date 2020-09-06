//
//
//  Kuyruktan ikili ağaca aktar
//
//

#include <stdio.h>
#include <stdlib.h>

struct kuyruk {
    int info;
    struct kuyruk *next;
};
typedef struct kuyruk *KUYRUKPTR;

struct tree {
    int info;
    struct tree *left;
    struct tree *right;
};
typedef struct tree *TREENODEPTR;

void insertTree(TREENODEPTR tree, int val) {
    TREENODEPTR temp = NULL;
    if(!(*tree)) {
    temp = (node *)malloc(sizeof(node));
    temp->left = temp->right = NULL;
    temp->data = val;
    *tree = temp;
    return;
    }
    if(val < (*tree)->data) {
        insert(&(*tree)->left, val);
    } else if(val > (*tree)->data) {
        insert(&(*tree)->right, val);
    }
}

void queue_to_tree(KUYRUKPTR *bas, KUYRUKPTR *son, TREENODEPTR *treeptr) {
    KUYRUKPTR currentPtr;
    int deger;
    currentPtr = bas;
    while(currentPtr != NULL) {
        deger = remove(bas, son);
        insertTree(treeptr, deger);
        currentPtr = bas;
    }
}