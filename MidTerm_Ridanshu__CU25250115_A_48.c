#include <stdio.h>
#include <stdlib.h>
int target_K;
int hamming_distance(int val, int k) {
    return __builtin_popcount(val ^ k);
}
int compare(const void *a, const void *b) {
    int num1 = *(const int *)a;
    int num2 = *(const int *)b;
    int dist1 = hamming_distance(num1, target_K);
    int dist2 = hamming_distance(num2, target_K);
    if (dist1 != dist2) {
        return dist1 - dist2;
    }
    return num1 - num2;
}
void solve() {
    int N;
    if (scanf("%d %d", &N, &target_K) != 2) return;
    int *A = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
    }
    qsort(A, N, sizeof(int), compare);
    for (int i = 0; i < N; ++i) {
        printf("%d%s", A[i], (i == N - 1) ? "" : " ");
    }
    printf("\n");
    free(A);
}
int main() {
    int T;
    if (scanf("%d", &T) == 1) {
        while (T--) {
            solve();
        }
    }
    return 0;
}
