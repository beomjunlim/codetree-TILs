#include <iostream>
#include <algorithm>
using namespace std;

int n,k;
char arr[1001];
int dp[1001][21][2];

int main() {
    cin>>n>>k;

    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }

    if(arr[1]=='L'){
        dp[1][0][0] = 1;
        dp[1][1][1] = 0;
    }
    else{
        dp[1][0][0] = 0;
        dp[1][1][1] = 1;
    }

    for(int i=2; i<=n; i++){
        for(int j=0; j<=k; j++){
            for(int l=0; l<2; l++){
                if(arr[i]=='L'){
                    dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j-1][1]) + 1;
                    dp[i][j][1] = max(dp[i-1][j-1][0], dp[i-1][j][1]);
                }
                if(arr[i]=='R'){
                    dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j-1][1]);
                    dp[i][j][1] = max(dp[i-1][j-1][0], dp[i-1][j][1]) + 1;
                }
            }
        }
    }

    int ans = 0;

    for(int i=0; i<=k; i++){
        for(int j=0; j<2; j++){
            ans = max(ans, dp[n][i][j]);
        }
    }

    cout<<ans;
    return 0;
}