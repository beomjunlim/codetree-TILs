#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 100000

int arr[MAX+1];
int dp[MAX+1];

int main() {
    int n;
    cin>>n;

    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }

    dp[1] = arr[1];

    for(int i=2; i<=n; i++){
        dp[i] = max(dp[i-1] + arr[i], arr[i]);
    }

    sort(dp+1, dp+n+1);
    cout<<dp[n];
    return 0;
}