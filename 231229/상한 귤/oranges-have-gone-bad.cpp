#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 100

int n,k;
int arr[MAX][MAX];
int cnt[MAX][MAX] = {0,};
bool visited[MAX][MAX] = {false,};
queue<pair<int,int>> q;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

bool InRange(int x, int y){
    return 0<=x&&x<n&&0<=y&&y<n;
}

void BFS(){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(InRange(nx,ny)&&!visited[nx][ny]&&arr[nx][ny]==1){
                cnt[nx][ny] = cnt[x][y] + 1;
                visited[nx][ny] = true;
                q.push(make_pair(nx,ny));
            }
        }

    }
}

int main() {
    cin>>n>>k;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
            if(arr[i][j]==2){
                visited[i][j] = true;
                q.push(make_pair(i,j));
            }
        }
    }

    BFS();
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j]==0)
                cout<<-1<<" ";
            else if(!visited[i][j])
                cout<<-2<<" ";
            else
                cout<<cnt[i][j]<<" ";
        }
        cout<<'\n';
    }
    return 0;
}