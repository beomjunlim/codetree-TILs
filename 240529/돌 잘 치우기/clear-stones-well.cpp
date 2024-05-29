#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int n,k,m;
int arr[100][100];
bool visited[100][100];
int idx = 0;
int ans = 0;
pair<int,int> start[10001];
pair<int,int> rock[10001];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

bool InRange(int x, int y){
    return 0<=x&&x<n&&0<=y&&y<n;
}

void bfs(){
    memset(visited, 0, sizeof(visited));
    queue<pair<int,int>> q;
    int cnt = 0;

    for(int i=0; i<k; i++){
        int x = start[i].first;
        int y = start[i].second;
        q.push(make_pair(x,y));
        visited[x][y] = true;
        cnt++;
    }

    while(!q.empty()){
        int nx = q.front().first;
        int ny = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int kx = nx + dx[i];
            int ky = ny + dy[i];

            if(InRange(kx,ky)&&!visited[kx][ky]&&arr[kx][ky]==0){
                q.push(make_pair(kx,ky));
                visited[kx][ky] = true;
                cnt++;
            }
        }
    }
    ans = max(ans, cnt);
}

void backtracking(int num, int index){
    if(num==m){
        bfs();
    }

    for(int i=index; i<idx; i++){
        int x= rock[i].first;
        int y = rock[i].second;
        arr[x][y] = 0;
        backtracking(num+1, i+1);
        arr[x][y] = 1;
    }
}

int main() {
    cin>>n>>k>>m;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
            if(arr[i][j]==1){
                rock[idx].first = i;
                rock[idx].second = j;
                idx++;
            }
        }
    }

    for(int i=0; i<k; i++){
        int r,c;
        cin>>r>>c;
        start[i].first = r-1;
        start[i].second = c-1;
    }

    backtracking(0,0);
    cout<<ans<<'\n';
    return 0;
}