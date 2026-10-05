//Return the number of special pairs to assist Alice in uncovering the hidden secret.
#include <stdio.h>

int digitSum(int n) {
    int sum = 0;

    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

long long solve(int N, int nums[]) {
    long long count = 0;

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {

            if (nums[i] <= nums[j] &&
                digitSum(nums[i]) == digitSum(nums[j])) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    int N;

    scanf("%d", &N);

    int nums[N];

    for (int i = 0; i < N; i++) {
        scanf("%d", &nums[i]);
    }

    printf("%lld\n", solve(N, nums));

    return 0;
}