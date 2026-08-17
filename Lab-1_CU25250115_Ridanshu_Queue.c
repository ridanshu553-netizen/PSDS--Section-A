#include <stdio.h>

int main() {
    int q[10]={10,20,30}, n=3;

    q[n++]=40;                // Enqueue
    printf("After enqueue: ");
    for(int i=0;i<n;i++) printf("%d ",q[i]);

    printf("\nDequeued: %d",q[0]);   // Dequeue
    for(int i=0;i<n-1;i++) q[i]=q[i+1];
    n--;

    printf("\nAfter dequeue: ");
    for(int i=0;i<n;i++) printf("%d ",q[i]);

    return 0;
}