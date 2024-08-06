#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

#define MOD 1000000007

int dp[1001][3][3];

int main() {
    int n;
    cin>>n;

    for(int i=0; i<=n; i++){
        for(int j=0; j<3; j++){
            for(int k=0; k<3; k++){
                dp[i][j][k] = 0;
            }
        }
    }

    dp[1][0][0] = 1;
    dp[1][1][0] = 1;
    dp[1][0][1] = 1;

    for(int i=2; i<=n; i++){
        for(int j=0; j<3; j++){
            for(int k=0; k<3; k++){
                if(dp[i-1][j][k]!=0){
                    if(j!=2)
                        dp[i][j+1][k] = (dp[i][j+1][k] + dp[i-1][j][k])%MOD;
                    if(k!=2)
                        dp[i][0][k+1] = (dp[i][0][k+1] + dp[i-1][j][k])%MOD;
                    dp[i][0][k] = (dp[i][0][k] + dp[i-1][j][k])%MOD;
                }
            }
        }
    }

    int ans = 0;
    for(int j=0; j<3; j++){
        for(int k=0; k<3; k++){
            ans += dp[n][j][k];
            ans %= MOD;
        }
    }
    cout<<ans;
    return 0;
}