// #include <iostream>
// #include <vector>
// #include <queue>
// using namespace std;

// // Max Heap
// void heapify(vector<int>& a, int n, int i) {
//     int largest = i;
//     int l = 2 * i + 1;
//     int r = 2 * i + 2;

//     if (l < n && a[l] > a[largest])
//         largest = l;

//     if (r < n && a[r] > a[largest])
//         largest = r;

//     if (largest != i) {
//         swap(a[i], a[largest]);
//         heapify(a, n, largest);
//     }
// }

// // Heap Sort
// void heapSort(vector<int>& a) {
//     int n = a.size();

//     // Build max heap
//     for (int i = n / 2 - 1; i >= 0; i--)
//         heapify(a, n, i);

//     // Extract elements
//     for (int i = n - 1; i > 0; i--) {
//         swap(a[0], a[i]);
//         heapify(a, i, 0);
//     }
// }

// int main() {
//     vector<int> a = {4, 10, 3, 5, 1};

//     // Priority Queue using Max Heap
//     priority_queue<int> pq;

//     for (int x : a)
//         pq.push(x);

//     cout << "Priority Queue: ";
//     while (!pq.empty()) {
//         cout << pq.top() << " ";
//         pq.pop();
//     }

//     // Heap Sort
//     heapSort(a);

//     cout << "\nHeap Sorted Array: ";
//     for (int x : a)
//         cout << x << " ";

//     return 0;
// }












// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int main() {
//     vector<int> a = {4, 2, 7, 1};

//     sort(a.begin(), a.end());

//     vector<int> b;
//     int l = 0, r = a.size() - 1;

//     while (l <= r) {
//         if (l <= r)
//             b.push_back(a[l++]);

//         if (l <= r)
//             b.push_back(a[r--]);
//     }

//     long long sum = 0;

//     for (int i = 1; i < b.size(); i++)
//         sum += abs(b[i] - b[i - 1]);

//     cout << "Rearranged Array: ";
//     for (int x : b)
//         cout << x << " ";

//     cout << "\nMaximum Sum: " << sum;

//     return 0;
// }





#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    vector<int> a = {2, 1, 5, 2, 3, 2};
    int target = 7;

    int left = 0;
    long long sum = 0;
    int ans = INT_MAX;

    for (int right = 0; right < a.size(); right++) {
        sum += a[right];

        while (sum > target) {
            ans = min(ans, right - left + 1);
            sum -= a[left];
            left++;
        }
    }

    if (ans == INT_MAX)
        cout << -1;
    else
        cout << "Smallest Subarray Length: " << ans;

    return 0;
}
