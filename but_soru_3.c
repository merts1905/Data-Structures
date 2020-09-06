//
//
//  Tek bağlı liste ve yığıtın elemanlarının ortalamasını bulan C programı
//
//

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct stack {
	int top;
	int ary[MAX];
};
typedef struct stack *STACKPTR;

struct node {
	int data;
	struct node * next;
};
typedef struct node *LINKEDPTR;

avg_of_linked_and_stack(LINKEDPTR head, STACKPTR ps) {
	struct node * pp;
    int sum_linked = 0;
    int num_linked = 0;
    int sum_stack = 0;
    int num_stack = 0;
	pp = head;
	while (pp != NULL) {
		sum_linked = pp->data + sum_linked;
		pp = pp->next;
        num_linked++;
	}

    while(ps->top > 0) {
        sum_stack = ps->ary[i] + sum_stack;
        num_stack++;
    }

    return (sum_linked + sum_stack) / (num_linked + num_stack);
}