#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push(int x) {
    struct Node *n = malloc(sizeof(struct Node));
    n->data = x;
    n->next = top;
    top = n;
}

void pop() {
    if (top == NULL)
        printf("Stack Underflow\n");
    else {
        struct Node *t = top;
        printf("Popped: %d\n", top->data);
        top = top->next;
        free(t);
    }
}

void display() {
    struct Node *t = top;
    while (t) {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);

    printf("Stack: ");
    display();

    pop();

    printf("After pop: ");
    display();

    return 0;
}