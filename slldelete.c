#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* head = NULL;
void deleteFirst() {
    if (head == NULL) return;
    struct Node* temp = head;
    head = head->next;
    free(temp);
}
void deleteValue(int value) {
    if (head == NULL) return;
    if (head->data == value) {
        deleteFirst();
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL && temp->next->data != value)
        temp = temp->next;
    if (temp->next == NULL) return;
    struct Node* target = temp->next;
    temp->next = target->next;
    free(target);
}
void deleteLast() {
    if (head == NULL) return;
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    struct Node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;
    free(temp->next);
    temp->next = NULL;
}
void display() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
int main() {
    int choice, value;
    while (1) {
        printf("\n1.Delete First\n2.Delete Value\n3.Delete Last\n4.Display\n5.Exit\n");
        scanf("%d", &choice);
        if (choice == 5) break;
        switch (choice) {
            case 1:
                deleteFirst();
                break;
            case 2:
                scanf("%d", &value);
                deleteValue(value);
                break;
            case 3:
                deleteLast();
                break;
            case 4:
                display();
                break;
        }
    }
    return 0;
}
