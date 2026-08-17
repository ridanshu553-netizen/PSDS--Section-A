#include <stdio.h>

int main() {
    int a[100],n,key,l=0,h,mid;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter sorted elements: ");
    for(int i=0;i<n;i++) scanf("%d",&a[i]);

    printf("Enter element to search: ");
    scanf("%d",&key);

    h=n-1;

    while(l<=h) {
        mid=(l+h)/2;

        if(a[mid]==key) break;
        else if(a[mid]<key) l=mid+1;
        else h=mid-1;
    }

    if(l<=h)
        printf("Element found at index %d",mid);
    else
        printf("Element not found");

    return 0;
}