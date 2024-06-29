#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

int n,k,u,d;
int ans = 0;
int arr[9][9];
bool visited_back[9][9];
bool visited[9][9];
vector<pair<int,int>> city;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

bool InRange(int x, int y){
    return 0<=x&&x<n&&0<=y&&y<n;
}

int bfs(){
    queue<pair<int,int>> q;
    int cnt = 0;
    memset(visited, false, sizeof(visited));

    for(int i=0; i<city.size(); i++){
        int x = city[i].first;
        int y = city[i].second;
        q.push(make_pair(x,y));
        visited[x][y] = true;
        cnt++;
    }

    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        int c_num = arr[cx][cy];
        q.pop();

        for(int i=0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            int n_num = arr[nx][ny];

            int num = abs(n_num - c_num);

            if(InRange(nx,ny)&&!visited[nx][ny]&&u<=num&&num<=d){
                cnt++;
                visited[nx][ny] = true;
                q.push(make_pair(nx,ny));
            }
        }
    }
    return cnt;
}

void backtracking(int idx_i, int idx_j, int cnt){
    if(cnt==k){
        int cnt = 0;
        cnt = bfs();
        ans = max(ans, cnt);
        return;
    }

    for(int i=idx_i; i<n; i++){
        for(int j=idx_j; j<n; j++){
            if(!visited_back[i][j]){
                visited_back[i][j] = true;
                city.push_back(make_pair(i,j));
                backtracking(i, j+1, cnt+1);
                visited_back[i][j] = false;
                city.pop_back();
            }
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
    cout<<ans;
    return 0;
}