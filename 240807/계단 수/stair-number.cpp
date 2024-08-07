#include <iostream>
#include <algorithm>
using namespace std;

#define MOD 1000000007

int n;
int dp[1001][10];

int main() {
    cin>>n;

    for(int i=0; i<=n; i++){
        for(int j=0; j<10; j++){
            dp[i][j] = 0;
        }
    }

    for(int i=1; i<=9; i++)
        dp[1][i] = 1;
    
    for(int i=2; i<=n; i++){
        for(int j=0; j<=9; j++){
            if(dp[i-1][j]!=0){
                if(j==9){
                    dp[i][j-1] = (dp[i][j-1] + dp[i-1][j]) % MOD;
                }
                else if(j==0){
                    dp[i][j+1] = (dp[i][j+1] + dp[i-1][j]) % MOD;
                }
                else{
                    dp[i][j-1] = (dp[i][j-1] + dp[i-1][j]) % MOD;
                    dp[i][j+1] = (dp[i][j+1] + dp[i-1][j]) % MOD;
                }
            }
        }
    }

    int ans = 0;

    for(int i=0; i<=9; i++){
        ans += dp[n][i];
        ans %= MOD;
    }

    cout<<ans;
    return 0;
}