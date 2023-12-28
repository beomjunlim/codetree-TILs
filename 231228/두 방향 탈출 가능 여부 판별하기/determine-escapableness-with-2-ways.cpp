#include <iostream>
using namespace std;

#define MAX 100

int n,m;
int arr[MAX][MAX];
bool visited[MAX][MAX] = {false, };
int dx[] = {0,1};
int dy[] = {1,0};
bool sw = false;

bool InRange(int x, int y){
    return 0<=x&&x<n&&0<=y&&y<m;
}

void DFS(int x, int y){
    visited[x][y] = true;

    if(x==n-1&&y==m-1){
        sw = true;
        return;
    }


    for(int i=0; i<2; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(InRange(nx,ny)&&!visited[nx][ny]&&arr[nx][ny]==1){
            DFS(nx,ny);
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
    DFS(0,0);

    if(sw)
        cout<<1<<'\n';
    else
        cout<<0<<'\n';
    return 0;
}