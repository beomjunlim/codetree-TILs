#include <iostream>
#include <algorithm>
using namespace std;

int n,m,a,b;
int Map[101][101];
int dp[101][101];

void myFunction(int r, int c){
    for(int i=r+1; i<=n; i++){
        for(int j=1; j<c; j++){
            Map[i][j] = -1;
        }
    }

    for(int i=1; i<r; i++){
        for(int j=c+1; j<=m; j++){
            Map[i][j] = -1;
        }
    }
}
int main() {
    cin>>n>>m>>a>>b;

    int r,c;
    for(int i=0; i<a; i++){
        cin>>r>>c;
        myFunction(r,c);
    }

    for(int i=0; i<b; i++){
        cin>>r>>c;
        Map[r][c] = -1;
    }

    dp[1][1] = 1;

    for(int i=2; i<=n; i++){
        if(Map[i][1]!=-1)
            dp[i][1] = dp[i-1][1];
        else
            dp[i][1] = 0;
    }

    for(int i=2; i<=m; i++){
        if(Map[1][i]!=-1)
            dp[1][i] = dp[1][i-1];
        else
            dp[1][i] = 0;
    }

    for(int i=2; i<=n; i++){
        for(int j=2; j<=m; j++){
            if(Map[i][j]!=-1){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    }

    cout<<dp[n][m];
    return 0;
}