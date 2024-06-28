#include <iostream>
#include <queue>
using namespace std;

int n,k;
int ans = 0;
int arr[101][101];
bool visited[101][101];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
queue<pair<int,int>> start;

bool InRange(int x, int y){
    return 0<=x&&x<n&&0<=y&&y<n;
}

void bfs(){
    while(!start.empty()){
        int x = start.front().first;
        int y = start.front().second;
        start.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(InRange(nx,ny)&&!visited[nx][ny]&&arr[nx][ny]==0){
                ans++;
                visited[nx][ny] = true;
                start.push(make_pair(nx,ny));
            }
        }
    }
}

int main() {
    cin>>n>>k;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0; i<k; i++){
        int a,b;
        cin>>a>>b;
        visited[a-1][b-1] = true;
        ans++;
        start.push(make_pair(a-1,b-1));
    }

    bfs();

    cout<<ans;
    return 0;
}