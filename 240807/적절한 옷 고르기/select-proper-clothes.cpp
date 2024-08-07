#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

#define MAX 201
int n,m;
int s[MAX];
int e[MAX];
int v[MAX];
int dp[MAX][MAX];

void Initialize(){
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            dp[i][j] = INT_MIN;
        }
    }

    for(int j=1; j<=n; j++){
        if(s[j] == 1)
            dp[1][j] = 0;
    }
}

int main() {
    cin>>n>>m;

    for(int i=1; i<=n; i++){
        cin>>s[i]>>e[i]>>v[i];
    }

    Initialize();

    for(int i=2; i<=m; i++){
        for(int j=1; j<=n; j++){
            for(int k=1; k<=n; k++){
                if(s[k]<=i-1 && i-1<=e[k] && s[j]<=i && i<= e[j])
                    dp[i][j] = max(dp[i][j], dp[i-1][k] +abs(v[j]-v[k]));
            }
        }
    }

    int ans = 0;
    for(int j=1; j<=n; j++)
        ans = max(ans, dp[m][j]);

    cout<<ans;
    return 0;
}