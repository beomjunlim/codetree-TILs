#include <iostream>
using namespace std;

int n,m;
bool sw = false;
bool visited[101][101];
int arr[101][101];
int dx[] = {1,0};
int dy[] = {0,1};

bool InRange(int x, int y){
    return 0<=x&&x<n&&0<=y&&y<m;
}

void dfs(int x, int y){
    if(x==n-1&&y==m-1){
        sw = true;
        return;
    }

    for(int i=0; i<2; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(InRange(nx,ny)&&arr[nx][ny]==1&&!visited[nx][ny]){
            visited[nx][ny] = true;
            dfs(nx,ny);
        }
    }
}

int main() {
    cin>>n>>m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }

    visited[0][0] = true;
    dfs(0,0);
    cout<<sw<<'\n';
    return 0;
}