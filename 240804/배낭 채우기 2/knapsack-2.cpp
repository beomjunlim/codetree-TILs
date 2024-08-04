#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int weight[101];
int value[101];
int dp[10001];

int main() {
    cin>>n>>m;

    for(int i=1; i<=n; i++){
        cin>>weight[i]>>value[i];
    }    


    for(int j=0; j<=m; j++){
        for(int i=1; i<=n; i++){
            if(weight[i]<=j)
                dp[j] = max(dp[j], dp[j- weight[i]] + value[i]);
        }
    }

    cout<<dp[m];

    return 0;
}