#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TABLE_SIZE 10007
#define INPUT_SIZE 5000


typedef struct {
	int id;
	char name[20];
}Student;

//해시 테이블 초기화
void init(Student ** hashtable) {
	for (int i = 0; i < TABLE_SIZE; i++) {
		hashtable[i] = NULL;
	}
}
//해시 테이블의 메모리를 반환
void destructor(Student** hashtable) {
	for (int i = 0; i < TABLE_SIZE; i++) {
		if (hashtable[i] != NULL) {
			free(hashtable[i]);
		}
	}
}
//해시 테이블 내 빈 공간을 선형 탐색으로 찾습니다.
int findEmpty(Student** hashtable, int id) {
	int i = id % TABLE_SIZE;
	while (1) {
		if (hashtable[i%TABLE_SIZE] == NULL) {
			return i % TABLE_SIZE;
		}
		i++;
	}
}
//특정한 ID 값에 매칭되는 데이터를 해시 테이블 내에서 찾습니다.
int search(Student** hashtable, int id) {
	int i = id % TABLE_SIZE;
	while (1) {
		if( hashtable[i % TABLE_SIZE] == NULL) return -1;
		else if (hashtable[i % TABLE_SIZE]->id == id) return i;
		i++;
	}
}
//특정한 키 인덱스에 데이터를 삽입
void add(Student** hashtable, Student* input, int key) {
	hashtable[key] = input;
}
// 해시 테이블에서 특정한 키의 데이터를 반환
Student* getValue(Student** hashtable, int key) {
	return hashtable[key];
}
//해시 테이블에 존재하는 모든 데이터를 출력
void show(Student** hashtable) {
	for (int i = 0; i < TABLE_SIZE; i++) {
		if (hashtable[i] != NULL) {
			printf("키: [%d] 이름: [%s]\n", i, hashtable[i]->name);
		}
	}
}

int main(void) {
	Student **hashtable;
	hashtable = (Student**)malloc(sizeof(Student) * TABLE_SIZE);
	init(hashtable);

	for (int i = 0; i < INPUT_SIZE; i++) {
		Student* student = (Student*)malloc(sizeof(Student));
		student->id = rand() % 1000000;
		sprintf(student->name, "사람%d", student->id);
		if (search(hashtable, student->id) == -1) {
			int index = findEmpty(hashtable, student->id);
			add(hashtable, student, index);
		}
	}
	show(hashtable);
	destructor(hashtable);
	system("pause");
	return 0;
}