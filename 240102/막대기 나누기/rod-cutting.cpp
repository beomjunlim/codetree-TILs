#include <iostream>
using namespace std;

#define MAX 100

int arr[MAX+1];
int dp[MAX+1];

int main() {
    int n;
    cin>>n;

    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }

    for(int i=1; i<=n; i++){
        dp[i] = arr[i];
        for(int j=1; j<i; j++){
            dp[i] = max(dp[i], dp[i-j] + arr[j]);
        }
    }

    cout<<dp[n];
    return 0;
}