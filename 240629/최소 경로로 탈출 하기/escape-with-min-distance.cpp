#include <iostream>
#include <queue>
using namespace std;

int n,m;
int ans = -1;
int arr[101][101];
bool visited[101][101];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

bool InRange(int x, int y){
    return 0<=x&&x<n&&0<=y&&y<m;
}

void bfs(){
    queue<pair<int,pair<int,int>>> q;
    q.push(make_pair(0, make_pair(0,0)));
    visited[0][0] = true;

    while(!q.empty()){
        int x = q.front().second.first;
        int y = q.front().second.second;
        int cnt = q.front().first;
        q.pop();

        if(x==n-1&&y==m-1){
            ans = cnt;
            break;
        }

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(InRange(nx,ny)&&!visited[nx][ny]&&arr[nx][ny]==1){
                visited[nx][ny] = true;
                q.push(make_pair(cnt+1, make_pair(nx,ny)));
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

    bfs();
    cout<<ans;
    return 0;
}