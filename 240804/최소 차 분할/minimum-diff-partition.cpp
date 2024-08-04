#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int arr[101];
bool dp[101][100001];

int main() {
    int n;
    cin>>n;

    int sum = 0;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
        sum += arr[i];
    }

    sort(arr, arr+n);
    dp[0][0] = true;

    for(int i=1; i<=n; i++){
        for(int j=0; j<=sum; j++){
            if(arr[i]<=j&&dp[i-1][j - arr[i]]){
                dp[i][j] = true;
            }
            if(dp[i-1][j])
                dp[i][j] = true;
        }
    }

    int ans = (int)1e9;

    for(int i=1; i<sum; i++){
        if(dp[n][i])
            ans = min(ans, abs(i - (sum-i)));
    }

    cout<<ans;
    return 0;
}