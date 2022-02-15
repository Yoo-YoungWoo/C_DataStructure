#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;


typedef struct stack {
    struct Node* top;
    int size;
}stack;

Node *initNode(int data) {
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

stack *initStack() {
    stack *newStack = malloc(sizeof(stack));
    newStack->top = NULL;
    newStack->size = 0;

    return newStack;
}


void push(stack *stack, int data) {
    Node *newNode = initNode(data);

    if(stack->top == NULL) {
        stack->top = newNode;
    } else {
        newNode->next = stack->top;
        stack->top = newNode;
    }
    stack->size++;
}

int pop(stack *stack) {
    Node *temp = stack->top;

    if(stack->size == 0) {
        printf("Error : Stack is Empty. \n");
        return -1;
    } else {
        int data = temp->data;
        stack->top = temp->next;
        stack->size--;
        free(temp);
        return data;
    }
}

int peek(stack *stack) {
    if(stack->size == 0) {
       printf("Error : Stack is Empty. \n");
       return -1;
    }
    return stack->top->data;
}

bool isEmpty(stack *stack) {
    return stack->size == 0;
}

void printStack(stack *stack) {
    Node *moveNode = stack->top;

    
    if(stack->size == 0) {
       printf("Error : Stack is Empty. \n");
       return;
    } else {
        printf("----------- \n");
        while(moveNode != NULL) {
            printf("\t%d \n", moveNode->data);

            moveNode = moveNode->next;
        }
        printf("-----------");
        printf("\n");
    }
}


int main() {
    stack *stack = initStack();

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);

    printStack(stack);
    printf("peek: %d \n", peek(stack));

    pop(stack);
    pop(stack);
    pop(stack);


    printStack(stack);

    return 0;
}