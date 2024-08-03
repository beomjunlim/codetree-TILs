#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int n,m;
int ice = 0;
int arr[201][201];
bool visited[201][201];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
int size = 0;

bool InRange(int x, int y){
    return 0<=x&&x<n&&0<=y&&y<m;
}

void bfs(){
    memset(visited, false, sizeof(visited));
    queue<pair<int,int>> q;
    q.push(make_pair(0,0));
    visited[0][0] = true;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(InRange(nx,ny)&&!visited[nx][ny]&&arr[nx][ny]==0){
                visited[nx][ny] = true;
                q.push(make_pair(nx,ny));
            }
        }
    }

    int cnt = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j]==1){
                bool sw = false;
                for(int k=0; k<4; k++){
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if(InRange(x,y)&&visited[x][y]){
                        sw = true;
                        break;
                    }
                }

                if(sw){
                    arr[i][j] = 0;
                    cnt++;
                }
            }
        }
    }
    size = cnt;
    ice -= cnt;
}


int main() {
    cin>>n>>m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
            if(arr[i][j]==1){
                ice++;
            }
        }
    }

    int time = 0;
    while(ice!=0){
        time++;
        bfs();
    }

    cout<<time<<" "<<size<<'\n';
    return 0;
}