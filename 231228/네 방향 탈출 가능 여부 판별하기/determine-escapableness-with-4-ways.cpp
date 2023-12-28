#include <iostream>
#include <queue>
using namespace std;

#define MAX 100

int n,m;
bool sw = false;
int arr[MAX][MAX];
bool visited[MAX][MAX];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

bool InRange(int x, int y){
    return 0<=x&&x<n&&0<=y&&y<m;
}

void BFS(int x, int y) {
    queue<pair<int,int>> q;
    visited[x][y] = true;
    q.push(make_pair(x,y));

    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        if(cx==n-1&& cy==m-1){
            sw = true;
        }

        for(int i=0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(InRange(nx,ny)&&!visited[nx][ny]&&arr[nx][ny]==1){
                visited[nx][ny] = true;
                q.push(make_pair(nx,ny));
            } 
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

    BFS(0,0);
    if(sw)
        cout<<1;
    else
        cout<<0;

    return 0;
}