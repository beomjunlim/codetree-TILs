#include <iostream>
#include <cstring>
using namespace std;

int n,m,r,c;
int cnt = 0;
int arr[100][100];
char dice[10000];
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int dir = 0;

bool InRange(int x, int y){
    return 0<=x&&x<n&&0<=y&&y<n;
}

int main() {
    memset(arr, 0, sizeof(arr));
    cin>>n>>m>>r>>c;

    for(int i=0; i<m; i++){
        cin>>dice[i];
    }

    int x = r - 1;
    int y = c - 1;
    int nx = x;
    int ny = y;
    arr[x][y] = 6;

    int up = 1;
    int right = 3;
    int front = 2;

    for(int i=0; i<m; i++){
        x = nx;
        y = ny;

        if(dice[i]=='U'){
            dir = 0;
            nx = x + dx[dir];
            ny = y + dy[dir];
            if(InRange(nx,ny)){
                arr[nx][ny] = 7 - front;
                int temp = up;
                up = front;
                front = 7 - temp;
            }
            else{
                nx = x;
                ny = y;
            }
        }
        else if(dice[i]=='D'){
            dir = 2;
            nx = x + dx[dir];
            ny = y + dy[dir];
            if(InRange(nx,ny)){
                arr[nx][ny] = front;
                int temp = up;
                up = 7 - front;
                front = temp;
            }
            else{
                nx = x;
                ny = y;
            }
        }
        else if(dice[i]=='L'){
            dir = 3;
            nx = x + dx[dir];
            ny = y + dy[dir];
            if(InRange(nx,ny)){
                arr[nx][ny] = 7 - right;
                int temp = up;
                up = right;
                right = 7 - temp;
            }
            else{
                nx = x;
                ny = y;
            }
        }
        else if(dice[i]=='R'){
            dir = 1;
            nx = x + dx[dir];
            ny = y + dy[dir];
            if(InRange(nx,ny)){
                arr[nx][ny] = right;
                int temp = up;
                up = 7 - right;
                right = temp;
            }
            else{
                nx = x;
                ny = y;
            }
        }
        //cout<<nx<<" "<<ny<<arr[nx][ny]<<'\n';
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
          //  cout<<arr[i][j]<<" ";
            cnt += arr[i][j];
        }
       // cout<<'\n';
    }
    cout<<cnt<<'\n';
    return 0;
}