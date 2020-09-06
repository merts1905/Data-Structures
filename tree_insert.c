//
//
//  Sayıları ağaca yerleştir
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

void insert_tree(TREEPTR root, int x) {
    TREEPTR new_node;
    new_node = (TREEPTR) malloc(sizeof(struct tree));
    new_node->info = x;
    new_node->left = NULL;
    new_node->right = NULL;

    if(root == NULL) {
        exit(0);
    }
    if(x < root->info) {
        root->left = insert_tree(root->left, x);
    }
    if(x > root->info) {
        root->right = insert_tree(root->right, x);
    }
    if(x == root->info) {
        exit(0);
    }
}