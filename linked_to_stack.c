//
//
//  Tek bağlı listeden yığına aktaran program
//
//

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct stack {
	int top;
	int ary[MAX];
};

struct stack mystack;

struct node {
	int data;
	struct node * next;
};

struct node * head = NULL;  
struct node * last = NULL;  

void push(struct stack * p, int x) {
	if (p->top > MAX-1 ) {
		printf("the stack is full\n");
		return;
	}
	(p->top)++;
	p->ary[mystack.top] = x;
	return;

}

void trans() {
	struct node * pp;
	pp = head;
	while (pp != NULL) {
		push(&mystack, pp->data);
		pp = pp->next;
	}
	
}
