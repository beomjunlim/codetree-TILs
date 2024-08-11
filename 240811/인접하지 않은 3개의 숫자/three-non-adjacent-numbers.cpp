#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];
int dp[100001][3][2];

int main() {
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    dp[0][0][0] = 0;
    dp[0][1][1] = arr[0];

    for(int i=1; i<n; i++){
        for(int j=1; j<=3; j++){
            dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1]);
            dp[i][j][1] = max(dp[i][j][1], dp[i-1][j-1][0] + arr[i]);
        }
    }

    int ans = 0;
    for(int i=1; i<=n; i++){
        ans = max(ans, max(dp[i][3][0], dp[i][3][1]));
    }

    cout<<ans;
    return 0;
}