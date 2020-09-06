//
//
//  Ağaçtaki eleman sayısı
//  Düzeltme için Esracan Güngör'e teşekkürler
//

#include <stdio.h>
#include <stdlib.h>

struct tree {
    int info;
    struct tree *left;
    struct tree *right;
};
typedef struct tree *TREEPTR;

int tree_number(TREEPTR root) {
    if(root == NULL) {
        return 0;
    }
    if(root->left == NULL && root->right == NULL) {
        return 1;
    }
    return tree_number(root_left) + tree_number(root_right);
}