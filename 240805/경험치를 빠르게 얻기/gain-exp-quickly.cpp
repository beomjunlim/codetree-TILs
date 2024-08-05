#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int n,m;
int arr[101];
int Exp[101];
int Time[101];
int dp[2][100001];

int main() {
    cin>>n>>m;

    int t = 0;
    for(int i=1; i<=n; i++){
        cin>>Exp[i]>>Time[i];
        t += Time[i];
    }    

    for(int i=0; i<2; i++){
        for(int j=0; j<=t; j++){
            dp[i][j] = INT_MIN;
        }
    }

    dp[0][0] = 0;

    for(int i=1; i<=n; i++){
        int a = i%2;
        int b = 1 - a;

        for(int j = 0; j <= t; j++)
            dp[a][j] = INT_MIN;

        for(int j=0; j<=t; j++){
            if(j - Time[i]>=0)
                dp[a][j] = max(dp[a][j], dp[b][j-Time[i]] + Exp[i]);
            
            dp[a][j] = max(dp[a][j], dp[b][j]);
        }
    }


    int ans = INT_MAX;
    for(int j=0; j<=t; j++)
        if(dp[n%2][j]>=m)
            ans = min(ans,j);
        
    if(ans==INT_MAX)
        ans = -1;
        
    cout<<ans;
    return 0;
}