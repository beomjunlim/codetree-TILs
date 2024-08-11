#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];
int dp[100001][4];

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i <= n; i++) {
        dp[i][0] = 
        dp[i][1] = dp[i][2] = dp[i][3] = -1e9;
    }

    for (int i = 1; i <= n; i++) {
        dp[i][0] = 0; 
        dp[i][1] = max(dp[i-1][1], arr[i]);

        if (i >= 2) {
            dp[i][2] = max(dp[i-1][2], dp[i-2][1] + arr[i]);
        }
        if (i >= 3) {
            dp[i][3] = max(dp[i-1][3], dp[i-2][2] + arr[i]);
        }
    }

    cout << dp[n][3] << endl;

    return 0;
}