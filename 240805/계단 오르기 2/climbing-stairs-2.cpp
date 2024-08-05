#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int n;
int coin[1001];
int dp[4][1001];

int main() {
    cin>>n;

    int sum = 0;
    
    for(int i=1; i<=n; i++){
        cin>>coin[i];
        sum += coin[i];
    }

    for(int i=0; i<4; i++){
        for(int j=0; j<=n; j++){
            dp[i][j] = INT_MIN;
        }
    }
    dp[0][0] = 0;
    dp[1][1] = coin[1];

    for(int i=2; i<=n; i++){
        dp[i][0] = max(dp[i][0], dp[i-2][0] + coin[i]);
        dp[i][1] = max(dp[i][1], max(dp[i-2][1] + coin[i], dp[i-1][0] + coin[i]));
        dp[i][2] = max(dp[i][2], max(dp[i-2][2] + coin[i], dp[i-1][1] + coin[i]));
        dp[i][3] = max(dp[i][3], max(dp[i-2][3] + coin[i], dp[i-1][2] + coin[i]));
    }

    int ans = max(dp[n][0], max(dp[n][1], max(dp[n][2], dp[n][3])));
    cout<<ans;

    return 0;
}