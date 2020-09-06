//
//
//  Ağaçtaki en büyük eleman
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

int findMax(TREEPTR root) 
{ 
    if (root == NULL) 
      return 0; 

    int root = root->data; 
    int max_left = findMax(root->left); 
    int max_right = findMax(root->right); 
    if (max_left > root) 
      root = max_left; 
    if (max_right > root) 
      root = max_right; 
    return root; 
}
