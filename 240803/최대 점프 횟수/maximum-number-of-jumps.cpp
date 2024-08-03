#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001];
int dp[1001];

int main() {
    int n;
    cin>>n;

    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    for(int i=0; i<n; i++){
        if(i!=0&&dp[i]==0)
            continue;
        for(int j=1; j<=arr[i]; j++){
            dp[i+j] = max(dp[i+j], dp[i] + 1);
        }
    }

    int ans = 0;
    for(int i=0; i<n; i++)
        ans = max(ans, dp[i]);
    
    cout<<ans;
    return 0;
}