#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;

    int dp[100001];

    dp[0] = 0;
    dp[2] = 1;
    dp[4] = 2;
    dp[5] = 1;
    for(int i=6; i<=n; i++){
        if(dp[i-5]==0&&dp[i-2]==0)
            dp[i] = 0;
        else if(dp[i-5]==0||dp[i-2]==0)
            dp[i] = max(dp[i-5], dp[i-2]) + 1;
        else
            dp[i] = min(dp[i-5],dp[i-2]) + 1;
    }

    if(dp[n]==0)
        cout<<-1;
    else
        cout<<dp[n];
    return 0;
}