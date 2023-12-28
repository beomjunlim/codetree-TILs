#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 100

int n,h,m;
int cnt=0;
int arr[MAX][MAX];
int ans[MAX][MAX] = {0, };
bool visited[MAX][MAX] = {false,};
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
queue<pair<int,int>> q;


bool InRange(int x, int y){
    return 0<=x&&x<n&&0<=y&&y<n;
}

void BFS(){
    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(InRange(nx,ny)&&!visited[nx][ny]&&arr[nx][ny]!=1){
                visited[nx][ny] = true;
                ans[nx][ny] = ans[cx][cy] + 1;
                q.push(make_pair(nx,ny));
            }
        }
    }
}


int main() {
    cin>>n>>h>>m;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
            if(arr[i][j]==3)
                q.push(make_pair(i,j));
        }
    }
    
    BFS();

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j] !=2)
                cout<<0<<" ";
            else{
                if(!visited[i][j])
                    cout<<-1<<" ";
                else
                    cout<<ans[i][j]<<" ";
            }
        }
        cout<<'\n';
    }
    return 0;
}