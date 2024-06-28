#include <iostream>
#include <cstring>
using namespace std;

int n,m;
int max_k = 0;
int ans_k = 0;
int ans = 0;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
bool visited[51][51];
int arr[51][51];
int area[51][51];

bool InRange(int x, int y){
    return 0<=x&&x<n&&0<=y&&y<m;
}

void madeArea(int k){
    memset(area, 0, sizeof(area));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j]<=k)
                area[i][j] = 1;
        }
    }
}

void dfs(int x, int y){
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(InRange(nx,ny)&&!visited[nx][ny]&&area[nx][ny]==0){
            visited[nx][ny] = true;
            dfs(nx,ny);
        }
    }
}

int main() {
    cin>>n>>m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
            if(max_k < arr[i][j])
                max_k = arr[i][j];
        }
    }

    for(int i=0; i<=max_k; i++){
        madeArea(i);
        memset(visited, false, sizeof(visited));
        int cnt = 0;
        for(int j=0; j<n; j++){
            for(int l=0; l<m; l++){
                if(area[j][l]==0&&!visited[j][l]){
                    visited[j][l] = true;
                    dfs(j,l);
                    cnt++;
                }
            }
        }

        if(ans < cnt){
            ans = cnt;
            ans_k = i;
        }
    }

    cout<<ans<<" "<<ans_k;
    return 0;
}