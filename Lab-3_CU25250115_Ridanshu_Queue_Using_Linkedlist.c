#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *front = NULL, *rear = NULL;

void enqueue(int x) {
    struct Node *n = malloc(sizeof(struct Node));
    n->data = x;
    n->next = NULL;

    if (rear == NULL)
        front = rear = n;
    else {
        rear->next = n;
        rear = n;
    }
}

void dequeue() {
    if (front == NULL)
        printf("Queue Underflow\n");
    else {
        struct Node *t = front;
        printf("Dequeued: %d\n", front->data);
        front = front->next;

        if (front == NULL)
            rear = NULL;

        free(t);
    }
}

void display() {
    struct Node *t = front;
    while (t) {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    printf("Queue: ");
    display();

    dequeue();

    printf("After dequeue: ");
    display();

    return 0;
}