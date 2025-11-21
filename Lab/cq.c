#include <stdio.h>
#define SIZE 3

int queue[SIZE];
int front = -1, rear = -1;

void insert(int item) {
    if ((front == 0 && rear == SIZE - 1) || (rear + 1) % SIZE == front) {
        printf("Queue Overflow\n");
    } else if (front == -1) {
        front = rear = 0;
        queue[rear] = item;
    } else {
        rear = (rear + 1) % SIZE;
        queue[rear] = item;
    }
}

void delete() {
    if (front == -1) {
        printf("Queue Empty\n");
    } else if (front == rear) {
        printf("Deleted: %d\n", queue[front]);
        front = rear = -1;
    } else {
        printf("Deleted: %d\n", queue[front]);
        front = (front + 1) % SIZE;
    }
}

void display() {
    if (front == -1) {
        printf("Queue Empty\n");
    } else {
        int i = front;
        while (1) {
            printf("%d ", queue[i]);
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        printf("\n");
    }
}

int main() {
    int choice, item;
    while (1) {
        printf("Enter your choice \n");
        printf("1.Insert \n 2.Delete \n 3.Display \n 4.Exit \n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                scanf("%d", &item);
                insert(item);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
        }
    }
}