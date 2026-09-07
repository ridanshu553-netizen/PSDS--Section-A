//3Sum Problem(-3,1,2):array--> 5,6,-3,8,1,9,2 
#include <stdio.h>

void threeSum(int arr[], int size, int target) {
    int found = 0;
    for (int i = 0; i < size - 2; i++) {
        for (int j = i + 1; j < size - 1; j++) {
            for (int k = j + 1; k < size; k++) {
                if (arr[i] + arr[j] + arr[k] == target) {
                    printf("Triplet found: %d, %d, %d\n", arr[i], arr[j], arr[k]);
                    found = 1;
                }
            }
        }
    }
    if (!found) {
        printf("No triplet found.\n");
    }
}

int main() {
    int arr[] = {5, 6, -3, 8, 1, 9, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    // Finding triplets that sum to 0 (since -3 + 1 + 2 = 0)
    int target = 0;
    threeSum(arr, size, target);

    return 0;
}

//Fibonacci Series
#include <stdio.h>

int fib(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fib(n - 1) + fib(n - 2);
}

int main() {
    int n;
    printf("Enter number of terms: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("%d ", fib(i));
    }
    printf("\n");

    return 0;
}

//Tower of Hanoi
#include <stdio.h>

void TOH(int n, int A, int B, int C) {
    if (n > 0) {
        TOH(n - 1, A, C, B);
        printf("%d %d\n", A, C);
        TOH(n - 1, B, A, C);
    }
}

int main() {
    // 3 disks, Peg 1 (Source), Peg 2 (Auxiliary), Peg 3 (Destination)
    TOH(3, 1, 2, 3);
    return 0;
}