//
//
//  İkili ağaçtan yığına aktar
//
//

#include <stdio.h>
#include <stdlib.h>
#define STACKSIZE 100

struct stack {
    int top;
    int info[STACKSIZE];
};
typedef struct stack *STACKPTR;

struct tree {
    int info;
    struct tree *left;
    struct tree *right;
};
typedef struct tree *TREEPTR;

void push(STACKPTR ps, int data) {
    if(ps->top == STACKSIZE-1) {
        exit(1);
    } else {
        ps->info[++(ps->top)] = data;
    }
}

void tree_to_stack(TREEPTR root, STACKPTR ps) {
    if(root != NULL) {
        tree_to_stack(root->left);
        tree_to_stack(root->right);
        push(ps, root->info);
    }
}