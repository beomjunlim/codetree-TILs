#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int n,h,m;
int arr[101][101];
int cnt[101][101];
bool visited[101][101];
vector<pair<int,int>> people;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

bool InRange(int x, int y){
    return 0<=x&&x<n&&0<=y&&y<n;
}

int bfs(int x, int y){
    memset(visited, false, sizeof(visited));
    queue<pair<int, pair<int,int>>> q;
    q.push(make_pair(0, make_pair(x,y)));
    visited[x][y] = true;

    while(!q.empty()){
        int cx = q.front().second.first;
        int cy = q.front().second.second;
        int cnt = q.front().first;
        q.pop();

        if(arr[cx][cy]==3){
            return cnt;
            break;
        }

        for(int i=0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];

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
        cnt[x][y] = bfs(x,y);
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<cnt[i][j]<<" ";
        }
        cout<<'\n';
    }
    return 0;
}