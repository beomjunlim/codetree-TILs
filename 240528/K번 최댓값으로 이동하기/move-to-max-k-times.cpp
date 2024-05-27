#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int n,k;
int arr[101][101];
bool visited[101][101];
int r,c;
int next_num = 0;
int next_x;
int next_y;
int dx[] = {-1,0,1,0};
int dy[] ={0,-1,0,1};

bool InRange(int x, int y){
    return 0<x&&x<=n&&0<y&&y<=n;
}

void bfs(int x, int y){
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    visited[x][y] = true;
    int num = arr[x][y];

    while(!q.empty()){
        int nx = q.front().first;
        int ny = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int kx = nx + dx[i];
            int ky = ny + dy[i];
            if(InRange(kx,ky)&&!visited[kx][ky]&&num>arr[kx][ky]){
                q.push(make_pair(kx,ky));
                visited[kx][ky] = true;
                if(next_num<arr[kx][ky]){
                    next_num = arr[kx][ky];
                    next_x = kx;
                    next_y = ky;
                }
                else if(next_num==arr[kx][ky]&&next_x==kx&&next_y>ky){
                    next_y = ky;
                }
                else if(next_num==arr[kx][ky]&&next_x>kx){
                    next_x = kx;
                    next_y = ky;
                }
            }
        }
    }
}

int main() {
    cin>>n>>k;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>arr[i][j];
        }
    }

    cin>>r>>c;

    for(int i=0; i<k; i++){
        memset(visited, 0, sizeof(visited));
        next_x = r;
        next_y = c;
        next_num = -1;
        bfs(r,c);
        if(r==next_x&&c==next_y)
            break;
        r = next_x;
        c = next_y;
    }

    cout<<r<<" "<<c<<'\n';
    return 0;
}