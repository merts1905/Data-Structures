//
//
//  İkili ağaçtaki elemanların toplamı
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

void tree_sum(TREEPTR root, int &sum){
    if (!root) 
        return; 
    if (!root->left && !root->right) 
        sum += root->data;
    tree_sum(root->left, sum); 
    tree_sum(root->right, sum); 
} 