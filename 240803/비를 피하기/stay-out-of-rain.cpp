#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int n,h,m;
int arr[101][101];
int ans[101][101];
bool visited[101][101];
int dx[] = {0,0,-1,1};
int dy[] ={-1,1,0,0};

bool InRange(int x, int y){
    return 0<=x&&x<n&&0<=y&&y<n;
}

int bfs(int i, int j){
    memset(visited, false, sizeof(visited));
    queue<pair<int, pair<int,int>>> q;
    q.push(make_pair(0,make_pair(i,j)));
    visited[i][j] = true;

    while(!q.empty()){
        int cnt = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();

        if(arr[x][y]==3){
            return cnt;
        }

        for(int k=0; k<4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];

            if(InRange(nx,ny)&&!visited[nx][ny]&&arr[nx][ny]!=1){
                visited[nx][ny] = true;
                q.push(make_pair(cnt+1, make_pair(nx,ny)));
            }
        }
    }
    return -1;
}

int main() {
    cin>>n>>h>>m;

    vector<pair<int,int>> people;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
            if(arr[i][j]==2){
                people.push_back(make_pair(i,j));
            }
        }
    }

    for(int i=0; i<h; i++){
        int x = people[i].first;
        int y = people[i].second;

        ans[x][y] = bfs(x,y);
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<'\n';
    }
    return 0;
}