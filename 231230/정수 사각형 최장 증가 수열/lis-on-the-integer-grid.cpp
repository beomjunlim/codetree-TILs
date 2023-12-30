#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 500

int n;
int arr[MAX][MAX];
int dp[MAX][MAX] ={0,};
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

bool InRange(int x, int y){
    return 0<=x&&x<n&&0<=y&&y<n;
}

int FindMax(int x, int y){
    if(dp[x][y]!=0)
        return dp[x][y];
    
    int cnt = 1;

    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(InRange(nx,ny)&&arr[nx][ny]>arr[x][y]){
            cnt = max(cnt, FindMax(nx,ny) + 1);
        }
    }

    return dp[x][y] = cnt;
}

int main() {
    cin>>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            ans = max(ans, FindMax(i,j));
        }
    }
    cout<<ans;
    return 0;
}