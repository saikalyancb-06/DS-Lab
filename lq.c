#include<stdio.h>
#include<stdlib.h>
#define max 5
int q[max];
int rear = -1;
int front = -1;

void enqueue(int item){
    if(rear == max-1){
        printf("Queue is full\n");
    }
    else if(front == -1){
        front = 0;
        rear = 0;
        q[rear] = item;
    }
    else{
        rear++;
        q[rear] = item;
    }
}
int dequeue(){
    int item;
    if(front == -1){
        printf("Queue is empty\n");
    }
    else if(front == rear){
        front = -1;
        rear = -1;
        item = q[rear];
        return item;
    }
    else{
        item = q[front];
        front++;
        return item;
    }
}

void display(){
    printf("Queue:");
    if(front == -1){
        printf("queue is empty");
    }
    else{
        for(int i=front;i<=rear;i++)
        printf("%d ",q[i]);
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nStack Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element you want to insert : ");
                int item;
                scanf("%d",&item);
                enqueue(item);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
