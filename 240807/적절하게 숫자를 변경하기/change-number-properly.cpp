#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int arr[501];
int dp[501][101][5];

int main() {
    cin>>n>>m;

    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }

    for(int i=1; i<=4; i++){
        if(arr[1]==i)
            dp[1][0][i] = 1;
        else
            dp[1][0][i] = 0;
    }

    for(int i=2; i<=n; i++){
        for(int j=0; j<=m; j++){
            for(int k=1; k<=4; k++){
                if(j==0){
                    if(arr[i]==k)
                        dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k] + 1);
                    else
                        dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k]);
                }
                else{
                    if(arr[i]==k){
                        for(int l=1; l<=4; l++){
                            if(l==k)
                                dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k] + 1);
                            else
                                dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-1][l] + 1);
                        }
                    }
                    else{
                        for(int l=1; l<=4; l++){
                            if(l==k)
                                dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k]);
                            else
                                dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-1][l]);
                        }
                    }
                }
            }
        }
    }

    int ans = 0;
    for(int i=0; i<=m; i++){
        for(int j=1; j<=4; j++){
            ans = max(ans, dp[n][i][j]);
        }
    }

    cout<<ans;
    return 0;
}