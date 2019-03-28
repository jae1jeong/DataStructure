#include <stdio.h>
#define INF 100000

int arr[INF];
int count = 0;

void addBack(int data) {
	arr[count] = data;
	count++;
}

void addFirst(int data) {
	for (int i = count; i >= 1; i--) {
		arr[i] = arr[i - 1];
	}
	arr[0] = data;
	count++;
}

void removeAt(int index) {
	for (int i = index; i < count; i++) {
		arr[i] = arr[i + 1];
	}
	count--;
}

void show() {
	for (int i = 0; i < count; i++) {
		printf("%d ", arr[i]);
	}
}

int main(void) {
	addFirst(1);
	addFirst(2);
	addFirst(3);
	addFirst(4);
	addBack(7);
	addBack(6);
	addBack(8);
	removeAt(1);
	show();
	system("pause");
	return 0;

}