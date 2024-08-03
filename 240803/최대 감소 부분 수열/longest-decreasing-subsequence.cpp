#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[1001];
int dp[1001];

int main() {
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>arr[i];
        dp[i] = 1;
    }

    for(int i=n-1; i>=0; i--){
        for(int j=0; j<=i; j++){
            if(arr[j]>arr[i])
                dp[j] = max(dp[j], dp[i] + 1);
        }
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        ans = max(ans, dp[i]);
    }
    
    cout<<ans;
    return 0;
}