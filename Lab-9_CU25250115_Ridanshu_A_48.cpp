//Determine the minimum number of operations required to make all the elements of A equal to zero.
//Else, print -1 if it is not possible to do so.
#include <stdio.h>

long long solve(int N, long long A[]) {
    long long sum = 0;
    long long positive = 0;
    long long negative = 0;

    for (int i = 0; i < N; i++) {
        sum += A[i];

        if (A[i] > 0)
            positive += A[i];
        else if (A[i] < 0)
            negative += A[i];
    }

    if (sum > 0)
        return -1;

    if (2 * positive > -negative)
        return -1;

    return -sum;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        scanf("%d", &N);

        long long A[N];

        for (int i = 0; i < N; i++) {
            scanf("%lld", &A[i]);
        }

        printf("%lld\n", solve(N, A));
    }

    return 0;
}