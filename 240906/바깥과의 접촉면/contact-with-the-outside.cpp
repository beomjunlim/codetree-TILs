#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int n,m;
int sum = 0;
int arr[101][101];
bool visited[101][101];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

bool InRange(int x, int y){
    return 0<=x&&x<n&&0<=y&&y<m;
}

int bfs(){
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

            if(InRange(nx,ny)&&!visited[nx][ny]){
                if(arr[nx][ny]==0){
                    q.push(make_pair(nx,ny));
                }
                visited[nx][ny] = true;
            }
        }
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(visited[i][j]&&arr[i][j]==1){
                arr[i][j] = 0;
                ans++;
            }
        }
    }
    return ans;
}
int main() {
    cin>>n>>m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
            if(arr[i][j]==1){
                sum++;
            }
        }
    }

    int answer = 0;
    int time = 0;
    while(sum!=0){
        time++;
        answer = bfs();
        sum -= answer;
    }

    cout<<time<<'\n';
    cout<<answer<<'\n';
    return 0;
}