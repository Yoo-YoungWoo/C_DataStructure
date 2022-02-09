#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    struct Node* next;  // 다음 노드의 주소를 저장할 포인터
    int data;
}Node;

typedef struct list {
    struct Node* head;
    int size;
}Llist;

Node *initNode(int data) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

Llist *initList() {
    Llist *newList = malloc(sizeof(Llist));
    newList->head = NULL;
    newList->size = 0;

    return newList;
}

// 노드 마지막에 삽입 
void addLast(Llist *list, int data) {
    Node *newNode = initNode(data);
    Node *moveNode = list->head;

    if(list->head == NULL) {
        list->head = newNode;
    } else{
        while(moveNode->next != NULL) {
            moveNode = moveNode->next;
        }
        moveNode->next = newNode;
    }
    list->size++;
}

// 노드 중간에 삽입
void addAt(Llist *list, int n, int data) {
    Node *newNode = initNode(data);
    Node *moveNode = list->head;

    if(n < 0 || list->size-1 < n || list->size == 0) {
        addLast(list, data);
        return;
    }

    if(n == 0) {
        newNode->next = list->head;
        list->head = newNode;
    } else {

        // 추가할 n번째 노드 이전 노드까지 이동
        for(int i = 0; i < n-1; i++) {
            moveNode = moveNode->next;
        }
        // 새로운 노드의 next에 이동한 노드의 다음 노드의 주소를 할당.
        //(ex: 3(newNode) -> newNode(4) -> 4(null))      
        newNode->next = moveNode->next;
        moveNode->next = newNode;
        list->size++;
    }
}

// 마지막 노드 삭제
void removeLast(Llist *list) {
    Node *moveNode = list->head;
    Node *prvNode;

    if(list->head == NULL) return;

    //리스트에 head노드 하나 있는 경우
    if(list->head->next == NULL) {

        free(list->head);
        list->head = NULL;
    } else {

        // 리스트의 헤드부터 시작하여 moveNode를 마지막 노드까지 이동
        while(moveNode->next != NULL) {
            prvNode = moveNode;
            moveNode = moveNode->next;
        }
        free(moveNode);
        
        prvNode->next = NULL;
        list->size--;
    }
}


// 중간 노드 삭제
void removeAt(Llist *list, int n) {
    Node *moveNode = list->head;
    Node *deleteNode;

    if(n < 0 || list->size-1 < n || list->head == NULL) {
        return;
    }

    if(n == 0) {
        list->head = list->head->next;
        free(moveNode);
        list->size--;
    } else {
        for(int i = 0; i < n-1; i++) {
            moveNode = moveNode->next;
        }
        //삭제할 노드 지정
        deleteNode = moveNode->next;

        // 현재 선택한 노드의 next를 다다음 노드로 변경
        //(3(5)(moveNode) -> 4(X)(deleteNode) -> 5(NULL))
        moveNode->next = moveNode->next->next;

        free(deleteNode);
        list->size--;
    }
}

void printList(Llist *list) {
    Node *moveNode = list->head;
    printf("List= ");

    while(moveNode != NULL) {
        printf("%d", moveNode->data);
        moveNode = moveNode->next;
        if(moveNode != NULL) {
            printf(",");
        }
    }

    printf("(Total = %d) \n", list->size);
    printf("\n");
}

// 리스트안 데이터가 있으면 몆 번째 있는지 반환 없으면 -1 반환
int indexOf(Llist *list, int data) {
    Node *moveNode = list->head;
    int index = 1;

    for(int i = 0; i < list->size; i++) {

        if(moveNode->data == data) {
            return index;
        } else {
            moveNode = moveNode->next;
            index++;
        }
    }
    return -1;
}

void destroyList(Llist *list) {
    Node *moveNode = list->head;

    while(moveNode != NULL) {
        list->head = list->head->next;

        free(moveNode);
        moveNode = list->head;
    }
    free(list);
}

int main() {
    Llist *list;
    
    list = initList();


    printf("addLast \n");
    addLast(list, 1);
    addLast(list, 2);
    addLast(list, 3);
    addLast(list, 4);
    addLast(list, 5);
    printList(list);
    printf("\n");


    printf("addAt \n");
    addAt(list, 3, 7);
    addAt(list, 6, 8);
    printList(list);
    printf("\n");


    printf("removeList \n");
    removeLast(list);
    removeAt(list, 0);
    printList(list);

    printf("destroyList \n");
    destroyList(list);
    printList(list);
    

    return 0;
}
