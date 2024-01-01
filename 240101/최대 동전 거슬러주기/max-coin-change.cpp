#include <iostream>
#include <climits>
 using namespace std;

 #define MAX_N 100
 #define MAX_M 10000

int coin[MAX_N];
int dp[MAX_M+1];

int main() {
    int n,m;
    cin>>n>>m;

    for(int i=0; i<n; i++){
        cin>>coin[i];
    }

    for(int i=1; i<=m; i++){
        dp[i] = INT_MIN;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<=m; j++){
            if(j>=coin[i]){
                if(dp[j-coin[i]]== INT_MIN)
                    continue;
                dp[j] = max(dp[j], dp[j-coin[i]] + 1);
            }
        }
    }

    if(dp[m]==INT_MIN)
        cout<<-1;
    else
        cout<<dp[m];
    return 0;
}