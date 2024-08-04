#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[501][501];
int dp[501][501];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

bool InRange(int x, int y){
    return 0<=x&&x<n&&0<=y&&y<n;
}

int main() {
    cin>>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
            dp[i][j] = 1;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<4; k++){
                int x = i + dx[k];
                int y = j + dy[k];

                if(InRange(x,y)&&arr[i][j]>arr[x][y])
                    dp[i][j] = max(dp[i][j], dp[x][y] + 1);
            }
        }
    }

    int ans = 0;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            ans = max(ans, dp[i][j]);
        }
    }

    cout<<ans;
    return 0;
}