#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int n,m;
int arr[101];
int dp[101][41];

int main() {
    cin>>n>>m;

    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }

    for(int i=1; i<=n; i++){
        for(int j=0; j<=40; j++){
            dp[i][j] = 0;
        }
    }

    dp[1][20 + arr[1]]++;
    dp[1][20 - arr[1]]++;

    for(int i=2; i<=n; i++){
        for(int j=0; j<=40; j++){
            if(dp[i-1][j]!=0){
                dp[i][j+arr[i]] += dp[i-1][j];
                dp[i][j-arr[i]] += dp[i-1][j];
            }
        }
    }

    // for(int i=1; i<=n; i++){
    //     for(int j=17; j<=23; j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<'\n';
    // }
    cout<<dp[n][20 + m];

    return 0;
}