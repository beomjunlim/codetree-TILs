#include <iostream>
#include <queue>
using namespace std;

int n,m;
bool sw = false;
int arr[101][101];
bool visited[101][101];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

bool InRange(int x, int y){
    return 0<=x&&x<n&&0<=y&&y<m;
}

void bfs(int x, int y){
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    visited[x][y] = true;

    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        if(cx==n-1&&cy==m-1){
            sw = true;
            break;
        }

        for(int i=0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if(InRange(nx,ny)&&!visited[nx][ny]&&arr[nx][ny]==1){
                q.push(make_pair(nx,ny));
                visited[nx][ny] = true;
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

    bfs(0,0);

    cout<<sw;
    return 0;
}