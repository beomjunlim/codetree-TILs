#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int n,m;
int arr[101];
int Exp[101];
int Time[101];
int dp[101][100001];

int main() {
    cin>>n>>m;

    int t = 0;
    for(int i=1; i<=n; i++){
        cin>>Exp[i]>>Time[i];
        t += Time[i];
    }    

    for(int i=0; i<=n; i++){
        for(int j=0; j<=t; j++){
            dp[i][j] = INT_MIN;
        }
    }

    dp[0][0] = 0;

    for(int i=1; i<=n; i++){
        for(int j=0; j<=t; j++){
            if(j - Time[i]>=0)
                dp[i][j] = max(dp[i][j], dp[i-1][j-Time[i]] + Exp[i]);
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
        }
    }


    int ans = INT_MAX;
    for(int j=0; j<=t; j++)
        if(dp[n][j]>=m)
            ans = min(ans, j);
        
    if(ans==INT_MAX)
        ans = -1;
        
    cout<<ans;
    return 0;
}