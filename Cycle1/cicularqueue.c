#include <stdio.h>
#include <stdlib.h>

int *a, front = 0, rear = 0, n;

void display() {
    int i;
    if (front == rear) {
        printf("\nQueue is empty\n");
        return;
    }
    printf("\nThe queue is:\n");
    i = (front + 1) % n;
    while (i != (rear + 1) % n) {
        printf("%d ", a[i]);
        i = (i + 1) % n;
    }
    printf("\n");
}

void push() {
    if (front == (rear + 1) % n) {
        printf("\nQueue overflow\n");
        return;
    }
    rear = (rear + 1) % n;
    printf("\nEnter the element to push: ");
    scanf("%d", &a[rear]);
    display();
}

void pop() {
    if (front == rear) {
        printf("\nQueue underflow\n");
        return;
    }
    front = (front + 1) % n;
    printf("\nPopped element: %d\n", a[front]);
    display();
}

int main() {
    int choice;

    printf("Enter the size of circular queue: ");
    scanf("%d", &n);

    a = (int *)malloc(n * sizeof(int));

    while (1) {
        printf("\nCircular Queue\n--------------\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: free(a); exit(0);
            default: printf("Invalid choice\n");
        }
    }
}
