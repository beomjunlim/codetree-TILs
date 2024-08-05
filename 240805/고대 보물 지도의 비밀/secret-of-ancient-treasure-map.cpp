#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int arr[100005];
int dp[100005][15];

int main() {
    int n, k;
    cin >> n >> k;

    for (int i=1; i<=n; i++) {
        cin >> arr[i];
    }

    int ans = -1e9;
    for(int i=1; i<=n; i++){
        if(arr[i]>=0){
            for(int j=0; j<=k; j++){
                dp[i][j] = max(dp[i-1][j] + arr[i], dp[i][j]);
                ans = max(ans, dp[i][j]);
            }
        }
        else{
            for(int j=1; j<=k; j++){
                dp[i][j] = max(dp[i-1][j-1] + arr[i], dp[i][j]);
                ans = max(ans, dp[i][j]);
            }
        }
    }

    cout<<ans;
    return 0;
}