#include <iostream>
using namespace std;

int n,m;
int arr[101][101];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

bool InRange(int x, int y){
    return 0<=x&&x<n && 0<=y && y<m;
}

int main() {
    cin>>n>>m;

    int x = 0, y = 0;
    int dir = 0;

    arr[x][y] = 1;

    for(int i=0; i<n*m-1; i++){
        int nx = x + dx[dir], ny = y + dy[dir];

        if(!InRange(nx,ny) || arr[nx][ny]!=0){
            dir = (dir+1) %4;
        }
        x = x + dx[dir];
        y = y + dy[dir];
        arr[x][y] = i + 2;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<'\n';
    }
    return 0;
}