#include <iostream>
using namespace std;

int weight[101];
int dp[101];

int main() {
    int n;
    cin>>n;

    for(int i=1; i<=n; i++){
        cin>>weight[i];
    }

    dp[1] = weight[1];

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(j-i>=0){
                dp[j] = max(dp[j], dp[j-i] + weight[i]);
            }
        }
    }

    cout<<dp[n];
    return 0;
}