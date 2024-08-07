#include <iostream>
#include <algorithm>
using namespace std;

int n;
int A[1001];
int B[1001];
int C[1001];
int dp[1001][3];

int main() {
    cin>>n;

    for(int i=1; i<=n; i++){
        cin>>A[i]>>B[i]>>C[i];
    }

    dp[1][0] = A[1];
    dp[1][1] = B[1];
    dp[1][2] = C[1];

    for(int i=2; i<=n; i++){
        dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + A[i];
        dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + B[i];
        dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + C[i];
    }

    int ans = max(dp[n][0], max(dp[n][1], dp[n][2]));
    cout<<ans;
    return 0;
}