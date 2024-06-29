#include <iostream>
#include <queue>
using namespace std;

int n,r1,r2,c1,c2;
int ans = -1;
int dx[] = {-2,-2,-1,-1,1,1,2,2};
int dy[] = {-1,1,-2,2,-2,2,-1,1};
bool visited[101][101];

bool InRange(int x, int y){
    return 0<=x&&x<n&&0<=y&&y<n;
}

void bfs(){
    queue<pair<int,pair<int,int>>> q;
    q.push(make_pair(0, make_pair(r1-1,c1-1)));
    visited[r1-1][c1-1] = true;

    while(!q.empty()){
        int x = q.front().second.first;
        int y = q.front().second.second;
        int cnt = q.front().first;
        q.pop();

        if(x==r2-1&&y==c2-1){
            ans = cnt;
            break;
        }

        for(int i=0; i<8; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(InRange(nx,ny)&&!visited[nx][ny]){
                visited[nx][ny] = true;
                q.push(make_pair(cnt+1, make_pair(nx,ny)));
            }
        }
    }
}

int main() {
    cin>>n;
    cin>>r1>>c1>>r2>>c2;

    bfs();
    cout<<ans;
    return 0;
}