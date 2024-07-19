#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    int arr[301][301] = {0};
    int sum[301][301] = {0};
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            sum[i][j] = arr[i][j] + sum[i][j-1];
        }
    }

    int ans = -(int)1e9;
    for (int left = 1; left <= n; left++) {
        for (int right = left; right <= n; right++) {
            int subarray_sum = 0;
            for (int row = 1; row <= n; row++) {
                subarray_sum += sum[row][right] - sum[row][left-1];
                ans = max(ans, subarray_sum);
                if (subarray_sum < 0) {
                    subarray_sum = 0;
                }
            }
        }
    }

    cout << ans;
    return 0;
}