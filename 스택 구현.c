#include <stdio.h>
#define SIZE 10000
#define INF 9999999

int stack[SIZE];
int top = -1;

void push(int data) {
	if (top == SIZE - 1) {
		printf("stackoverflow has been ocurred");
		return;
	}
	stack[++top] = data;
}
void pop() {
	if (top == -1) {
		printf("stackunderflow has been ocurred");
		return -INF;
	}
	return stack[top--];
}
void show() {
	printf("--스택의 최상단--\n");
	for (int i = top; i >= 0; i--) {
		printf("%d\n", stack[i]);
	}
	printf("--스택의 최하단--\n");
}
int main(void) {
	push(1);	
	push(2);
	push(3);
	push(4);
	pop();
	push(5);
	show();
	system("pause");
	return 0;
}