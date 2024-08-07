#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int n,m;
int arr[101];
long long dp[101][41];

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
                if(j+arr[i]<=40)
                    dp[i][j+arr[i]] += dp[i-1][j];
                if(j-arr[i]>=0)
                    dp[i][j-arr[i]] += dp[i-1][j];
            }
        }
    }

    cout<<dp[n][20 + m];

    return 0;
}