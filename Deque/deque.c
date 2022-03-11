#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
}Node;


typedef struct list {
    struct Node *head;
    struct Node *tail;
    int size;
}list;


Node *initNode(int data) {
    Node *initNode = malloc(sizeof(Node));

    initNode->data = data;
    initNode->next = NULL;
    initNode->prev = NULL;
    

    return initNode;
}


list *initList() {
    list *initList = malloc(sizeof(list));

    initList->head = NULL;
    initList->tail = NULL;
    initList->size = 0;

    return initList;
}


void enqueue(list *deque, int data) {
    Node *newNode = initNode(data);

    if(deque->tail == NULL) {
        deque->head = deque->tail = newNode;
    } else {
        deque->tail->next = newNode;
        newNode->prev = deque->tail;
        deque->tail = newNode;
    }

    deque->size++;
}

void enqueueFirst(list *deque, int data) {
    Node *newNode = initNode(data);

    if(deque->head == NULL) {
        deque->head = deque->tail = newNode;
    } else {
        newNode->next = deque->head;
        deque->head->prev = newNode;
        deque->head = newNode;
    }
    deque->size++;
}


int dequeue(list *deque) {
    Node *nextNode = deque->head->next;

    if(deque->head == NULL) {
        printf("Deque is Empty \n");
        return -1;
    }

    int data = deque->head->data;

    // head노드의 next자리를 NULL로 바꿔서 연결 끊기
    deque->head->next = NULL;
    
    // 노드가 2개 이상일 경우에만 앞에 노드에 접근 가능
    if(nextNode != NULL) {
        nextNode->prev = NULL;
    }

    free(deque->head);
    deque->head = nextNode;
    deque->size--;

    return data;
}

int dequeLast(list *deque) {
    Node *prevNode = deque->tail->prev;

    if(deque->tail == NULL) {
        printf("Deque is Empty \n");
        return -1;
    }


    int data = deque->tail->data;

    deque->tail->prev = NULL;

    // 노드가 2개 이상일 경우에만 뒤의 노드에 접근 가능
    if(prevNode != NULL) {
        prevNode->next = NULL;
    }

    free(deque->tail);
    deque->tail = prevNode;
    deque->size--;

    return data;
}


void printQueue(list *deque) {

    for(Node *i = deque->head; i != NULL; i = i->next) {
        printf("%d ", i->data);
    }
    printf("\n");
}

int main() {
    list *deque = initList();

    enqueue(deque, 1);
    enqueue(deque, 2);
    enqueueFirst(deque, 12);
    enqueueFirst(deque, 8);
    enqueueFirst(deque, 5);

    // 5 8 12 1 2
    printQueue(deque);

    // 5 8 12 1
    dequeue(deque);
    // 8 12 1
    dequeLast(deque);
    

    printQueue(deque);

    return 0;
}