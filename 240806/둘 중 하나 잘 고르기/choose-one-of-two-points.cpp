#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int n;
int R[201];
int B[201];
int dp[201][101];

int main() {
    cin >> n;

    for(int i=1; i<=2*n; i++) {
        cin >> R[i] >> B[i];
    }


    for (int i=0; i<=2*n; i++) {
        for (int j=0; j<=n; j++) {
            dp[i][j] = INT_MIN;
        }
    }

    dp[0][0] = 0;

    for(int i=1; i<=2*n; i++){
        for(int j=0; j<=i; j++){
            if(j>0)
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + R[i]);
            if(i-j>0)
                dp[i][j] = max(dp[i][j], dp[i-1][j] + B[i]);
        }
    }

    cout << dp[2 * n][n] << endl;
    return 0;
}