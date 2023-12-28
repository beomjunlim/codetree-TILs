#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 100

int n;
int cnt=0;
int arr[MAX][MAX];
bool visited[MAX][MAX] = {false, };
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

bool InRange(int x, int y){
    return 0<=x&&x<n&&0<=y&&y<n;
}

void DFS(int x, int y){
    visited[x][y] = true;
    cnt++;
    int num = arr[x][y];

    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(InRange(nx,ny)&&!visited[nx][ny]&&num==arr[nx][ny])
            DFS(nx,ny);
    }
}

int main() {
    int ans = 0;
    int max_cnt = 0;
    cin>>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!visited[i][j]){
                cnt = 0;
                DFS(i,j);
                max_cnt = max(max_cnt, cnt);
                if(cnt>=4){
                    ans+=1;
                }
            }
        }
    }

    cout<<ans<<" "<<max_cnt;
    return 0;
}