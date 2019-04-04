#include <stdio.h>
#include <stdlib.h>
#include "stack.h"



int Initialize(Stack *s, int max) {
	s->ptr = 0; //스택이 비어있어야 함
	if ((s->stk = calloc(max, sizeof(int)) == NULL)) {
		s->max = 0; //배열의 생성에 실패
		return -1;
	}
	s->max = max;
	return 0;
}
int isEmpty(const Stack *s) {
	return s->ptr <= 0;
}
int Push(Stack* s, int data) {
	if (s->ptr >= s->max)
		return -9999;
	s->stk[s->ptr++] = data;
	return 0;
}
int Pop(Stack *s, int *data) {
	if (s->ptr <= 0)
		return -9998;
	*data = s->stk[--s->ptr];
	return 0;
}
void Terminate(Stack *s) {
	if (s->stk != NULL)
		free(s->stk);
	s->max = s -> ptr = 0;
}

