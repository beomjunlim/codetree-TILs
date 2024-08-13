#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];

int main() {
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int ans = 0;
    int i = 0, j = n - 1;

    while (i < j) {
        if (arr[i] + arr[j] <= k) {
            ans += (j - i); // j와의 쌍 모두 카운트
            i++; // i를 증가시켜 더 큰 값을 고려
        } else {
            j--; // j를 감소시켜 더 작은 값을 고려
        }
    }

    cout << ans;
    return 0;
}