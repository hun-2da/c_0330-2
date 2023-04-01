#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct {
	int *stack_m;
	int top;
	int capacity;
}element;
element *e;

int is_empty() {
	return (e->top == -1);
}
int is_full() {
	return (e->top == (e-> capacity - 1));
}
void push(int item) {
	if (is_full()) {
		fprintf(stderr, "stack full\n");
		e->capacity = e->capacity* 2;
		e->stack_m = realloc(e->stack_m, e->capacity * sizeof(int));
		return;
	}
	else e->stack_m[++e->top] = item;
}
int pop() {
	if (is_empty()) {
		fprintf(stderr, "stack empty\n");
		return -1;
	}
	else return e->stack_m[e->top--];
}
int main() {
	element *m = malloc(sizeof(element));
	m->top = -1;
	m->capacity = 10;
	m->stack_m = malloc(m->capacity*sizeof(int));
	
	
	e = m;

	srand(time(NULL));
	printf("----Using array----\n");
	for (int i = 1; i <= 30; i++) {

		int rand_num = rand() % 100 + 1;
		if (rand_num % 2 == 1) {
			printf("[%3d]pop %d\n", i, pop());

		}else {
			printf("[%3d]push %d\n", i, rand_num);
			push(rand_num);

		}
	}
	free(m->stack_m);
	free(m);

	system("pause");
}