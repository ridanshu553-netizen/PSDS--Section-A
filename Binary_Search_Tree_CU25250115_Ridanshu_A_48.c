#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int x) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = x;
    n->left = n->right = NULL;
    return n;
}

struct Node* insert(struct Node* r, int x) {
    if (!r) return newNode(x);
    if (x < r->data) r->left = insert(r->left, x);
    else r->right = insert(r->right, x);
    return r;
}

struct Node* min(struct Node* r) {
    while (r->left) r = r->left;
    return r;
}

struct Node* del(struct Node* r, int x) {
    if (!r) return r;
    if (x < r->data) r->left = del(r->left, x);
    else if (x > r->data) r->right = del(r->right, x);
    else {
        if (!r->left) return r->right;
        if (!r->right) return r->left;
        struct Node* t = min(r->right);
        r->data = t->data;
        r->right = del(r->right, t->data);
    }
    return r;
}

void in(struct Node* r) {
    if (r) { in(r->left); printf("%d ", r->data); in(r->right); }
}

void pre(struct Node* r) {
    if (r) { printf("%d ", r->data); pre(r->left); pre(r->right); }
}

void post(struct Node* r) {
    if (r) { post(r->left); post(r->right); printf("%d ", r->data); }
}

int main() {
    struct Node* root = NULL;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);

    printf("Inorder: "); in(root);
    printf("\nPreorder: "); pre(root);
    printf("\nPostorder: "); post(root);

    root = del(root, 30);
    printf("\nAfter deletion: "); in(root);

    return 0;
}