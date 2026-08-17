#include <stdio.h>

int main() {
    int a[10]={1,2,3}, n=3, x;

    a[n++]=4;                 // Push
    printf("After push: ");
    for(int i=0;i<n;i++) printf("%d ",a[i]);

    x=a[--n];                 // Pop
    printf("\nPopped: %d",x);

    printf("\nAfter pop: ");
    for(int i=0;i<n;i++) printf("%d ",a[i]);

    return 0;
}