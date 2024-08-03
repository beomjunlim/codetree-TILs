#include <iostream>
using namespace std;

int dp[1001];

int main() {
    int n;
    cin>>n;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    dp[4] = 5;
    dp[5] = 9;

    for(int i=6; i<=n; i++)
        dp[i] = (dp[i-1] + dp[i-2] + dp[i-5]) % 10007;
    
    cout<<dp[n];
    return 0;
}