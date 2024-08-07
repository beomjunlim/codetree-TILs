#include <iostream>
#include <algorithm>
using namespace std;

int n;
int A[1001];
int B[1001];
int C[1001];
int dp[1001][3][3];

int main() {
    cin>>n;

    for(int i=1; i<=n; i++){
        cin>>A[i]>>B[i]>>C[i];
    }

    dp[1][0][0] = A[1];
    dp[1][1][1] = B[1];
    dp[1][2][2] = C[1];

    for(int i=2; i<n; i++){
        for(int j=0; j<3; j++){
            dp[i][0][j] = max(dp[i-1][1][j], dp[i-1][2][j]) + A[i];
            dp[i][1][j] = max(dp[i-1][0][j], dp[i-1][2][j]) + B[i];
            dp[i][2][j] = max(dp[i-1][0][j], dp[i-1][1][j]) + C[i];
        }
    }

    int ans = 0;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(i==0&&i!=j){
                dp[n][i][j] = max(dp[n-1][1][j], dp[n-1][2][j]) + A[n];
            }
            else if(i==1&&i!=j){
                dp[n][i][j] = max(dp[n-1][0][j], dp[n-1][2][j]) + B[n];
            }
            else if(i==2&&i!=j){
                dp[n][i][j] = max(dp[n-1][0][j], dp[n-1][1][j]) + C[n];
            }
            ans = max(ans, dp[n][i][j]);
        }
    }

    cout<<ans;
    return 0;
}