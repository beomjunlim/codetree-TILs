#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

int n,k,r1,r2,c1,c2;
int arr[101][101];
int ans = 987654321;
bool visited[101][101];
int wall[9];
vector<pair<int,int>> walls;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

bool InRange(int x, int y){
    return 0<=x&&x<n&&0<=y&&y<n;
}

void bfs(){
    memset(visited, false, sizeof(visited));
    queue<pair<int, pair<int,int>>> q;
    q.push(make_pair(0,make_pair(r1,c1)));
    visited[r1][c1] = true;

    while(!q.empty()){
        int x = q.front().second.first;
        int y = q.front().second.second;
        int cnt = q.front().first;
        q.pop();

        if(x==r2&&y==c2){
            ans = min(ans, cnt);
            break;
        }

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(InRange(nx,ny)&&!visited[nx][ny]&&arr[nx][ny]==0){
                visited[nx][ny] = true;
                q.push(make_pair(cnt + 1, make_pair(nx,ny)));
            }
        }
    }
}

void backtracking(int num, int cnt){
    if(cnt==k){
        for(int i=0; i<k; i++){
            int x = walls[wall[i]].first;
            int y = walls[wall[i]].second;
            arr[x][y] = 0;
        }
        
        bfs();

        for(int i=0; i<k; i++){
            int x = walls[wall[i]].first;
            int y = walls[wall[i]].second;
            arr[x][y] = 1;
        }
        return;
    }

    for(int i=num; i<walls.size(); i++){
        wall[cnt] = i;
        backtracking(i+1, cnt+1);
    }
}

int main() {
    cin>>n>>k;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
            if(arr[i][j]==1){
                walls.push_back(make_pair(i,j));
            }
        }
    }

    cin>>r1>>c1;
    cin>>r2>>c2;

    r1 = r1 - 1;
    c1 = c1 - 1;
    r2 = r2 - 1;
    c2 = c2 - 1;

    backtracking(0,0);
    if(ans==987654321)
        ans = -1;
    cout<<ans;
    return 0;
}