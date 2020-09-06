//
//
//  Ağacın sağ ve sol kolundaki elemanları bulan program
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

int tree_left_right_number(TREEPTR root) {
    int toplam;
    tree_left_right_number(root->left);
    toplam++;
    tree_left_right_number(root->right);
    return toplam;
}