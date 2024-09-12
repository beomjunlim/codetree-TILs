#include <iostream>
using namespace std;

int day[16];
int dp[16];

int main() {
    int n,w;
    cin>>n>>w;

    for(int i=1; i<=n; i++){
        cin>>day[i];
    }

    dp[1] = w;

    for(int i=2; i<=n; i++){
        if(day[i]>day[i-1]){
            int num = dp[i-1]/day[i-1];
            int coin = dp[i-1]%day[i-1];

            dp[i] = num*day[i] + coin;
        }
        else
            dp[i] = dp[i-1];
    }

    cout<<dp[n];
    return 0;
}