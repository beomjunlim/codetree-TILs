#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int n;
int arr[10001];
int ans[10001];
int dp[10001][11]; // LEFT 몇 번

int main() {
    cin>>n;

    for(int i=1; i<=n; i++){
        char a;
        cin>>a;
        arr[i] = a - '0';
    }

    for(int i=1; i<=n; i++){
        char a;
        cin>>a;
        ans[i] = a - '0';
    }

    for(int i=0; i<=n; i++){
        for(int j=0; j<=9; j++){
            dp[i][j] = INT_MAX;
        }
    }

    dp[0][0] = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<=9; j++){
            if(dp[i][j]==INT_MAX)  
                continue;
            
            int cur = (arr[i+1] + j) % 10;
            int target = ans[i+1];
            
            int cost = (target - cur + 10) % 10;
            int nj = (j + cost) % 10;
            dp[i+1][nj] = min(dp[i+1][nj], dp[i][j] + cost);

            cost = (cur - target + 10) % 10;
            nj = j;
            dp[i+1][nj] = min(dp[i+1][nj], dp[i][j] + cost);
        }
    }

    int ans = INT_MAX;
    for(int i=0; i<=9; i++){
        ans = min(ans, dp[n][i]);
    }

    cout<<ans;
    return 0;
}