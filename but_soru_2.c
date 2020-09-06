//
//
//  İkili ağaçtaki elemanların toplamını ve sayısını veren C programı
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

void tree_number(TREEPTR root, int &number) {
    if(root !== NULL) {
        tree_number(root->left);
        tree_number(root->right);
        number ++;
    }
}

main(int argc, char const *argv[])
{
    int number = 0;
    tree_number(root, &number);
    int sum = 0;
    tree_sum(root, &sum);

    return 0;
}
