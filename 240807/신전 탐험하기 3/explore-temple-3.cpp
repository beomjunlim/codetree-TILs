#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int arr[1001][101];
int dp[1001][101];

int main() {
    cin>>n>>m;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>arr[i][j];
        }
    }

    for(int i=1; i<=m; i++)
        dp[1][i] = arr[1][i];
    
    for(int i=2; i<=n; i++){
        for(int j=1; j<=m; j++){
            for(int k=1; k<=m; k++){
                if(j!=k){
                    dp[i][j] = max(dp[i][j], dp[i-1][k] + arr[i][j]);
                }
            }
        }
    }

    int ans = 0;
    for(int i=1; i<=m; i++)
        ans = max(ans, dp[n][i]);
    
    cout<<ans;
    return 0;
}