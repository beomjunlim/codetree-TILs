#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n,m;
int arr[201][201];
bool visited[201][201];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

bool InRange(int x, int y){
    return 0<=x&&x<n&&0<=y&&y<m;
}

int bfs(){
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
                q.push(make_pair(nx,ny));
                visited[nx][ny] = true;
            }
        }
    }

    int ice = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j]==1){
                for(int k=0; k<4; k++){
                    int x = i + dx[k];
                    int y = j + dy[k];

                    if(InRange(x,y)&&arr[x][y]==0&&visited[x][y]){
                        visited[i][j] = true;
                        ice++;
                        break;
                    }
                }
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(visited[i][j])
                arr[i][j] = 0;
        }
    }
    return ice;
}

int main() {
    cin>>n>>m;
    
    int cnt = 0;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
            if(arr[i][j]==1)
                cnt++;
        }
    }   

    int time = 0;
    int ice = 0;
    while(cnt>0){
        time++;
        ice = bfs();
        cnt -= ice;
    }

    cout<<time<<" "<<ice<<'\n';
    return 0;
}