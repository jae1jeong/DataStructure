#include <stdio.h>
#include <stdlib.h>
#define INF 9999999999

typedef struct {
	int data;
	struct Node *next;
}Node;

typedef struct {
	Node *top;
}Stack;

void push(Stack *stack, int data) {
	Node *node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = stack->top;
	stack->top = node;
}
int pop(Stack *stack) {
	if (stack->top == NULL) {
		printf("Stack underflow has been ocurred\n");
		return -INF;
	}
	Node *node = stack->top;
	int data = node->data;
	stack->top = node->next;
	free(node);
	return data;
}
void show(Stack *stack) {
	Node *cur = stack->top;
	printf("--스택의 최상단--\n");
	while (cur != NULL) {
		printf("%d\n", cur->data);
		cur = cur->next;
	}
	printf("--스택의 최하단--\n");
}

int main(void) {
	Stack s;
	s.top = NULL; 
	pop(&s);
	show(&s);
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	push(&s, 4);
	pop(&s);
	push(&s, 5);
	show(&s);
	system("pause");
	return 0;
}