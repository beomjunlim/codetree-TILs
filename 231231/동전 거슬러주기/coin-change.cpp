#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

#define MAX_m 10001
#define MAX_n 100

int arr[MAX_n];
int dp[MAX_m];

int main() {
    int n,m;
    cin>>n>>m;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    for(int i=1; i<=m; i++){
        dp[i] = INT_MAX;
    }

    for(int i=0; i<=m; i++){
        for(int j=0; j<n; j++){
            if(arr[j]<=i){
                if(dp[i-arr[j]]==INT_MAX)
                    continue;
                dp[i] = min(dp[i], dp[i-arr[j]] + 1);
            }
        }
    }

    if(dp[m]==INT_MAX)
        cout<<-1;
    else
        cout<<dp[m];
    return 0;
}