#include <iostream>
using namespace std;

#define MAX_N 100
#define MAX_M 10000

int weight[MAX_N+1];
int value[MAX_N+1];
int dp[MAX_N+1][MAX_M+1];

int main() {
    int n,m;
    cin>>n>>m;

    for(int i=1; i<=n; i++){
        cin>>weight[i];
        cin>>value[i];
    }

    for(int i=1; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(j>=weight[i]){
                dp[i][j] = max(dp[i-1][j], dp[i][j-weight[i]] + value[i]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout<<dp[n][m];
    return 0;
}