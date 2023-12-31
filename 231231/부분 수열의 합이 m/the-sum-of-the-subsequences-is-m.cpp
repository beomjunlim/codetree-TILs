#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

#define MAX_N 100
#define MAX_M 10000

int arr[MAX_N];
int dp[MAX_M+1];

int main() {
    int n,m;
    cin>>n>>m;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    for(int i=1; i<=m; i++){
        dp[i] = MAX_N+1;
    }

    for(int i=0; i<n; i++){
        for(int j=m; j>=0; j--){
            if(arr[i]<=j){
                dp[j] = min(dp[j], dp[j-arr[i]] + 1);
            }
        }
    }

    if(dp[m] == MAX_N + 1)
        cout<<-1;
    else
        cout<<dp[m];
    return 0;
}