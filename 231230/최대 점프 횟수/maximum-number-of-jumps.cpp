#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

#define MAX 1000

int arr[MAX];
int dp[MAX];

int main() {
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>arr[i];
        dp[i] = INT_MIN;
    }

    dp[0] = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(dp[j] == INT_MIN)
                continue;
            if(arr[j]>=i-j){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    sort(dp, dp+n);

    cout<<dp[n-1];
    return 0;
}