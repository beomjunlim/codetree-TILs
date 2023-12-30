#include <iostream>
using namespace std;

#define MAX 1000

int arr[MAX+1];
int dp[MAX+1];

int main() {
    int n;
    cin>>n;

    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }

    arr[0] = dp[0] = 0;

    for(int i=1; i<=n; i++){
        for(int j=0; j<i; j++){
            if(arr[j]<arr[i]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }

    
    int ans=0;

    for(int i=0; i<=n; i++){
        ans = max(ans, dp[i]);
    }

    cout<<ans;

    return 0;
}