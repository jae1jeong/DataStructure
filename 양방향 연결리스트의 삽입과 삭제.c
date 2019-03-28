#include <stdio.h>
#include<stdlib.h>

typedef struct {
	int data;
	struct Node *prev;
	struct Node *next;
}Node;

Node *head, *tail;

void insert(int data) {
	Node* node = (Node*)malloc(sizeof(Node)); //노드 메모리 할당
	node->data = data; //노드에 데이터 삽입
	Node* cur; //현재를 가르키는 노드를 생성
	cur = head->next; //노드 헤드 다음으로 위치 설정
	while (cur ->data <data &&cur != tail) { // 순회하고 있는 데이터가 데이터보다 작고 순회하고 있는 cur이 tail이 아닐때까지
		cur = cur->next; // cur은 계속 다음으로 이동
	}
	Node* prev = cur->prev; //prev노드를 만들어 이 노드의 위치는 현재 노드의 prev
	prev->next = node; //prev 다음 노드는 node로 설정
	node->prev = prev; //node 전에 노드는 prev로 설정
	node->next = cur; //node 다음 노드는 cur로 설정
	cur->prev = node; //cur 이전 노드는 노드로 설정
}

void removeFront() {
	Node* node = head->next; //노드는 head의 다음으로 설정
	head->next = node->next; //head 다음은 node의 다음으로 설정
	Node* next = node->next; //next 노드는 node의 next 노드로 설정
	next->prev = head; //next 이전 노드는 head로 설정
	free(node);
}
void show() {
	Node* cur = head->next; //cur 노드를 head 다음으로 지정 
	while (cur != tail) { //tail이 아닐 때까지 순회하면서 cur의 데이터를 출력
		printf("%d ", cur->data);
		cur = cur->next; //반복할 때마다 cur 다음으로 설정
	}
}

int main(void) {
	head = (Node*)malloc(sizeof(Node));
	tail = (Node*)malloc(sizeof(Node));
	head->next = tail;
	head->prev = NULL;
	tail->next = NULL;
	tail->prev = head;
	insert(2);
	insert(3);
	insert(4);
	insert(5);
	insert(6);
	removeFront();
	show();
	system("pause");
	return 0;
}
