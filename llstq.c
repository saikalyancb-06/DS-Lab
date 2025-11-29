
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

struct Node* push(struct Node* top, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = top;
    top = newNode;
    return top;
}

struct Node* pop(struct Node* top) {
    if (top == NULL) {
        printf("Stack Underflow!\n");
        return NULL;
    }

    struct Node* temp = top;
    top = top->next;
    free(temp);
    return top;
}

struct Node* enqueue(struct Node* front, int value) {
    struct Node* newNode = createNode(value);

    if (front == NULL)
        return newNode;

    struct Node* temp = front;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return front;
}

struct Node* dequeue(struct Node* front) {
    if (front == NULL) {
        printf("Queue Underflow!\n");
        return NULL;
    }

    struct Node* temp = front;
    front = front->next;
    free(temp);

    return front;
}

void display(struct Node* head) {
    if (head == NULL) {
        printf("Empty\n");
        return;
    }
    struct Node* temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *stack = NULL, *queue = NULL;
    int choice, value;

    while (1) {
        printf("1. Stack PUSH\n");
        printf("2. Stack POP\n");
        printf("3. Display Stack\n");
        printf("4. Queue ENQUEUE\n");
        printf("5. Queue DEQUEUE\n");
        printf("6. Display Queue\n");
        printf("0. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                stack = push(stack, value);
                break;

            case 2:
                stack = pop(stack);
                break;

            case 3:
                printf("Stack: ");
                display(stack);
                break;

            case 4:
                printf("Enter value: ");
                scanf("%d", &value);
                queue = enqueue(queue, value);
                break;

            case 5:
                queue = dequeue(queue);
                break;

            case 6:
                printf("Queue: ");
                display(queue);
                break;

            case 0:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
