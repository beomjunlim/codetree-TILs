#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int n,k,u,d;
int arr[8][8];
bool visited[8][8];
pair<int,int> city[3];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
int ans = 0;

bool InRange(int x, int y){
    return 0<=x&&x<n&&0<=y&&y<n;
}

void bfs(){
    memset(visited, 0, sizeof(visited));
    queue<pair<int,int>> q;
    int cnt = 0;

    for(int i=0; i<k; i++){
        q.push(make_pair(city[i].first, city[i].second));
        visited[city[i].first][city[i].second] = true;
        cnt++;
    }

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        int num = arr[x][y];
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(InRange(nx,ny)&&!visited[nx][ny]&&abs(arr[nx][ny]-num)<=d&&abs(arr[nx][ny] - num)>=u){
                q.push(make_pair(nx,ny));
                visited[nx][ny] = true;
                cnt++;
            }
        }
    }
    ans = max(ans, cnt);
}
void backtracking(int num, int idx_i, int idx_j){
    if(num==k){
        bfs();
    }

    for(int i= idx_i; i<n; i++){
        for(int j= idx_j; j<n; j++){
            city[num].first = i;
            city[num].second = j;
            if(j==n-1)
                backtracking(num+1,i+1,0);
            else
                backtracking(num+1,i, j+1);
        }
    }
}

int main() {
    cin>>n>>k>>u>>d;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    backtracking(0,0,0);
    cout<<ans<<'\n';
    return 0;
}