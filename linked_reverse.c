//
//
//  Tek bağlı listeyi tersine çevir
//
//

#include <stdio.h>
#include <stdlib.h>

struct Node 
{ 
    int data; 
    struct Node* next; 
}; 
  
static void reverse(struct Node** head_ref) 
{ 
    struct Node* prev   = NULL; 
    struct Node* current = *head_ref; 
    struct Node* next = NULL; 
    while (current != NULL) 
    { 
        next  = current->next;   
        current->next = prev;    
        prev = current; 
        current = next; 
    } 
    *head_ref = prev; 
}
