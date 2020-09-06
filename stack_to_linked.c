//
//
//  Yığıttan tek bağlı listeye aktar
//  Düzeltme için Fatih Cesur'a teşekkürler
//

#include <stdio.h>
#include <stdlib.h>

#define STACKSIZE 100

struct linked {
    int info;
    struct linked *next;
};
typedef struct linked *LINKEDPTR;

struct stack {
    int top;
    int info[STACKSIZE];
};
typedef struct stack *STACKPTR;

void insert(LINKEDPTR head, int value) {
    LINKEDPTR q;
    if(head == NULL) {
        head = (LINKEDPTR) malloc(sizeof(struct linked));
        head->info = value;
        head->next = NULL;
        return;
    }
    q = (LINKEDPTR) malloc(sizeof(struct linked));
    q->info = value;
    q->next = NULL;
    if(head->next == NULL) {
        head->next = q;
    }
    else {
        LINKEDPTR current = head;
        while(1) {
            if(current->next == NULL) {
                current->next = q;
                break;
            }
            current = current->next;
        }
    }
}

void stack_to_linked(STACKPTR stack, LINKEDPTR list) {
    
    for(int i = 0; i < stack->top; i++)
    {
        insert(list, stack->info[i]);
    }
    
}
