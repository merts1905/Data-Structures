//
//
//  İkili ağaçtan çift bağlı listeye aktar
//
//

#include <stdio.h>
#include <stdlib.h>

struct node 
{ 
    int data; 
    struct node *left, *right; 
};

void fixPrevPtr(struct node *root) 
{ 
    static struct node *pre = NULL;
    if (root != NULL) 
    { 
        fixPrevPtr(root->left); 
        root->left = pre; 
        pre = root; 
        fixPrevPtr(root->right); 
    } 
} 
  
struct node *fixNextPtr(struct node *root) 
{ 
    struct node *prev = NULL;   
    while (root && root->right != NULL) 
        root = root->right;
    while (root && root->left != NULL) 
    { 
        prev = root; 
        root = root->left; 
        root->right = prev; 
    } 
    return (root); 
} 
  
struct node *BTToDLL(struct node *root) 
{ 
    fixPrevPtr(root);  
    return fixNextPtr(root); 
}