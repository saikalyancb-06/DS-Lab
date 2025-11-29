#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertEnd(struct Node* head, int value) {
    struct Node* newNode = createNode(value);

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

void sortList(struct Node* head) {
    struct Node* i;
    struct Node* j;
    int temp;

    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* nextNode;

    while (current != NULL) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    return prev;
}

struct Node* concatenate(struct Node* head1, struct Node* head2) {
    if (head1 == NULL)
        return head2;

    struct Node* temp = head1;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head2;
    return head1;
}

void display(struct Node* head) {
    struct Node* temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *list1 = NULL, *list2 = NULL;
    int choice, value;

    while (1) {
        printf("1. Insert into List 1\n");
        printf("2. Insert into List 2\n");
        printf("3. Sort List 1\n");
        printf("4. Reverse List 1\n");
        printf("5. Concatenate List1 & List2\n");
        printf("6. Display List 1\n");
        printf("7. Display List 2\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                list1 = insertEnd(list1, value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                list2 = insertEnd(list2, value);
                break;

            case 3:
                sortList(list1);
                printf("List 1 Sorted.\n");
                break;

            case 4:
                list1 = reverseList(list1);
                printf("List 1 Reversed.\n");
                break;

            case 5:
                list1 = concatenate(list1, list2);
                printf("Lists Concatenated.\n");
                break;

            case 6:
                display(list1);
                break;

            case 7:
                display(list2);
                break;

            case 0:
                exit(0);

            default:
                printf("Invalid Choice!\n");
        }
    }
    return 0;
}
