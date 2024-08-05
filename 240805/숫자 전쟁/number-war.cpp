#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int A[1001];
int B[1001];
int dp[1001][1001]; 

int main() {
    int n;
    cin>>n;

    int A_idx;
    int B_idx;

    for(int i=1; i<=n; i++){
        cin>>A[i];
    }
    
    for(int i=1; i<=n; i++){
        cin>>B[i];
    }

    dp[0][0] = 0; 
    dp[0][1] = 0;

    int a,b,c;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(A[i]>B[j])
                dp[i][j] = max(dp[i][j], dp[i][j-1] + B[j]);
            else
                dp[i][j] = max(dp[i][j], dp[i-1][j]);
            dp[i][j] = max(dp[i][j], dp[i-1][j-1]);
        }
    }

    cout<<dp[n][n];
    return 0;
}