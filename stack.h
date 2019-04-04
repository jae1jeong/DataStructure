

typedef struct {
	int ptr; //포인터
	int max; //용량
	int *stk; //스택의 첫 요소에 대한 포인터
}Stack;

int Initialize(Stack *s, int max);
int isEmpty(const Stack *s);
int Push(Stack *s, int data);
int Pop(Stack *s, int *data);
void Terminate(Stack *s);