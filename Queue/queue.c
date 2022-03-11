#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;


typedef struct list {
    struct Node *front;
    struct Node *rear;
    int size;
}list;


Node *initNode(int data) {
    Node *newNode = malloc(sizeof(Node));

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

list *initList() {
    list *newList = malloc(sizeof(list));

    newList->front = NULL;  // exit
    newList->rear = NULL;  // enterance
    newList->size = 0;

    return newList;
}

void enqueue(list *queue, int data) {
    Node *newNode = initNode(data);

    if(queue->rear == NULL) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    queue->size++;
}


int dequeue(list *queue) {

    Node *tmp = queue->front;

    if(queue->front == NULL) {
        printf("Queue is Empty! \n");
        return - 1;
    }
    int data = tmp->data;


    queue->front = tmp->next;
    queue->size--;
    tmp = NULL;
    free(tmp);
    return data;
}

int peek(list *queue) {

    if(queue->front == NULL) {
        printf("Queue is Empty! \n");
        return - 1;
    }
    
    return queue->front->data;
}

void printQueue(list *queue) {

    for(Node *i = queue->front; i != NULL; i = i->next) {
        printf("%d ", i->data);
    }
    printf("\n");

}


int main() {

    list *queue = initList();

    
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);

    printf("%d \n", peek(queue));
    printQueue(queue);


    dequeue(queue);
    printQueue(queue);

    dequeue(queue);
    
    // 3
    printQueue(queue);

    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    

}

