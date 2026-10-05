//Given an array of N integers, find the maximum sum of any contiguous subarray of size K.
// #include <stdio.h>

// int main() {
//     int a[100000], n, k, i;
//     long long sum = 0, max;

//     scanf("%d%d", &n, &k);

//     for(i = 0; i < n; i++)
//         scanf("%d", &a[i]);

//     for(i = 0; i < k; i++)
//         sum += a[i];

//     max = sum;

//     for(i = k; i < n; i++) {
//         sum += a[i] - a[i-k];
//         if(sum > max) max = sum;
//     }

//     printf("%lld", max);
//     return 0;
// }

//Given a string S, find the length of the longest substring without repeating characters.
// #include <stdio.h>

// int main() {
//     char s[1000000];
//     int last[26] = {0}, left = 0, max = 0, i, len;

//     scanf("%s", s);

//     for(i = 0; s[i]; i++) {
//         int x = s[i] - 'a';

//         if(last[x] > left)
//             left = last[x];

//         last[x] = i + 1;

//         len = i - left + 1;
//         if(len > max) max = len;
//     }

//     printf("%d", max);
//     return 0;
// }

//You are given a weighted, undirected graph with N nodes and M edges. Find the shortest path from node 1 to node N such 
//that the path uses at most K edges. If no such path exists, output -1.
#include <stdio.h>

#define INF 1000000000

struct Edge {
    int u, v, w;
};

int main() {
    struct Edge e[10000];
    int n, m, k, dp[1001], ndp[1001];
    int i, j, ans;

    scanf("%d%d%d", &n, &m, &k);

    for(i = 0; i < m; i++)
        scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);

    for(i = 1; i <= n; i++) dp[i] = INF;
    dp[1] = 0;

    for(i = 1; i <= k; i++) {
        for(j = 1; j <= n; j++) ndp[j] = dp[j];

        for(j = 0; j < m; j++) {
            if(dp[e[j].u] != INF &&
               dp[e[j].u] + e[j].w < ndp[e[j].v])
                ndp[e[j].v] = dp[e[j].u] + e[j].w;

            if(dp[e[j].v] != INF &&
               dp[e[j].v] + e[j].w < ndp[e[j].u])
                ndp[e[j].u] = dp[e[j].v] + e[j].w;
        }

        for(j = 1; j <= n; j++) dp[j] = ndp[j];
    }

    ans = dp[n];

    printf("%d", ans == INF ? -1 : ans);
    return 0;
}

//6 3
//2 1 5 1 3 2

//abcabcbb

//5 6 3
//1 2 2
//1 3 5
//2 3 1
//2 4 4
//3 5 2
//4 5 1








