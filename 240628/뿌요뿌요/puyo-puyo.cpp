#include <iostream>
#include <algorithm>
using namespace std;

int n;
int block = 0;
int max_block = 0;
int bomb_block = 0;
int arr[101][101];
bool visited[101][101];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

bool InRange(int x, int y){
    return 0<=x&&x<n&&0<=y&&y<n;
}

void dfs(int x, int y){
    int num = arr[x][y];

    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(InRange(nx,ny)&&!visited[nx][ny]&&num==arr[nx][ny]){
            bomb_block++;
            visited[nx][ny] = true;
            dfs(nx,ny);
        }
    }
}

int main() {
    cin>>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!visited[i][j]){
                bomb_block = 1;
                visited[i][j] = true;
                dfs(i,j);
                max_block = max(max_block, bomb_block);
                if(bomb_block>3){
                    block++;
                }
            }
        }
    }

    cout<<block<<" "<<max_block;
    return 0;
}