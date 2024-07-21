// This is the source file for Problem5_202217b3002.c


#include <stdio.h>
#include <stdlib.h>

#define n 5 // Define the size of the queue

void display(int queue[], int front, int rear) {
    if (front == rear) {
        printf("\nQueue is Empty\n");
    } else {
        printf("\nQueue Elements are:\n");
        for (int i = front; i < rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int queue[n], ch = 1, front = 0, rear = 0, j = 1;
    
    printf("Queue using Array");
    printf("\n1. Insertion \n2. Deletion \n3. Display \n4. Exit");

    while (ch) {
        printf("\nEnter the Choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                if (rear == n) {
                    printf("\nQueue is Full\n");
                } else {
                    printf("\nEnter no %d: ", j++);
                    scanf("%d", &queue[rear++]);
                }
                break;

            case 2:
                if (front == rear) {
                    printf("\nQueue is Empty\n");
                } else {
                    printf("\nDeleted Element is %d\n", queue[front++]);
                    if (front == rear) { // Reset the queue if it becomes empty
                        front = 0;
                        rear = 0;
                        j = 1;
                    }
                }
                break;

            case 3:
                display(queue, front, rear);
                break;

            case 4:
                exit(0);

            default:
                printf("Wrong Choice: please see the options\n");
        }
    }
    return 0;
}


