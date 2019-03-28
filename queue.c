#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 1000
#define INF 999999999

int a[SIZE];

int queue[SIZE];
int front,rear = 0;

// 큐 삽입 함수
void push(int data) {
	if (rear >= SIZE) {
		printf("큐 오버플로우가 발생하였습니다.\n");
		return;
	}
	queue[rear++] = data;
}
// 큐 추출 함수
void pop() {
	if (front == rear) {
		printf("큐 언더플로우가 발생하였습니다.\n");
		return -INF;
	}
	return queue[front];
	front++;
}

void show() {
	printf("----큐의 앞-----\n");
	for (int i = front; i < rear; i++) {
		printf("%d\n", queue[i]);
	}
	printf("----큐의 뒤-----\n");
}

int main(void) {
	push(1);
	pop();
	push(2);
	push(3);
	pop();
	show();
	system("pause");
	return 0;
}