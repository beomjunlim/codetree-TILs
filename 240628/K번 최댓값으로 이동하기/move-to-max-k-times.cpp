#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n,k;
int start_x, start_y;
int arr[101][101];
bool visited[101][101];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

bool InRange(int x, int y){
    return 0<=x&&x<n&&0<=y&&y<n;
}

void bfs(int x, int y){
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    visited[x][y] = true;
    int num = arr[x][y];
    int idx_x = x;
    int idx_y = y;
    int max_num = 0;

    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if(InRange(nx,ny)&&!visited[nx][ny]&&arr[nx][ny] < num){
                q.push(make_pair(nx,ny));
                visited[nx][ny] = true;
                if(max_num < arr[nx][ny]){
                    idx_x = nx;
                    idx_y = ny;
                    max_num = arr[nx][ny];
                }
                else if(max_num == arr[nx][ny]&&nx<idx_x){
                    idx_x = nx;
                    idx_y = ny;
                }
                else if(max_num == arr[nx][ny]&&nx==idx_x&&ny<idx_y){
                    idx_y = ny;
                }
            }
        }
    }
    start_x = idx_x;
    start_y = idx_y;
}

int main() {
    cin>>n>>k;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    int r,c;
    cin>>r>>c;
    start_x = r-1;
    start_y = c-1;
    for(int i=0; i<k; i++){
        memset(visited, false, sizeof(visited));
        bfs(start_x, start_y);
    }

    cout<<start_x+1<<" "<<start_y+1<<'\n';

    return 0;
}