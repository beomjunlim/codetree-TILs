#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        int left = lower_bound(arr, arr + n, a) - arr;

        int right = upper_bound(arr, arr + n, b) - arr;


        int cnt = right - left;

        cout << cnt << '\n';
    }

    return 0;
}