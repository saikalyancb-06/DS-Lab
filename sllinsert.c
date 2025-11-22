#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insertAtFirst(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void insertAtPosition(int value, int pos) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }
    struct Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL) return;
    newNode->next = temp->next;
    temp->next = newNode;
}

void display() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int choice, value, pos;
    while (1) {
        printf("\n 1.Insert at First\n 2.Insert at End\n 3.Insert at Position\n 4.Display\n 5.Exit\nEnter choice: ");
        scanf("%d", &choice);
        if (choice == 5) break;
        switch (choice) {
            case 1:
                scanf("%d", &value);
                insertAtFirst(value);
                break;
            case 2:
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3:
                scanf("%d", &value);
                scanf("%d", &pos);
                insertAtPosition(value, pos);
                break;
            case 4:
                display();
                break;
        }
    }
    return 0;
}
