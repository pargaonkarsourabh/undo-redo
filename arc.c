#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 512

typedef struct {
	char items[STACK_SIZE];
	int top;
} Stack;

void push(Stack *stack, char elem) {
	stack->items[++stack->top] = elem;
}
char pop(Stack *stack) {
	return stack->items[stack->top--];
}
char peek(Stack *stack) {
	return stack->items[stack->top];
}
int isEmpty(Stack *stack) {
	return stack->top == -1;
}
void display(Stack *stack) {
	int i;
	for (i = 0; i <= stack->top; i++) {
		printf("%c", stack->items[i]);
	}
}
void emptyStack(Stack *stack) {
	while(!isEmpty(stack)) pop(stack);
}

int main() {
	Stack undo, redo;
	undo.top = redo.top = -1;
	
	char input;
	do {
		system("cls");
		printf("Enter . to exit program\nEnter - to undo and + to redo\n");
		display(&undo);
		input = getch();
		if (input == '+') {
			if (!isEmpty(&redo)) push(&undo, pop(&redo));
		}
		else if (input == '-') {
			if (!isEmpty(&undo)) push(&redo, pop(&undo));
		}
		else {
			push(&undo, input);
			//empty redo stack
			emptyStack(&redo);
		}
	}
	while(input != '.');
	return 0;
}
