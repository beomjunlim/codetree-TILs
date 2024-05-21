#include <iostream>
#include <algorithm>
using namespace std;

int n;
int ans = 0;
int arr[100][100];
int dx[] = {-1,0,1,0}; // ^ > V <
int dy[] = {0,1,0,-1};

bool InRange(int x, int y){
    return 0<=x&&x<n&&0<=y&&y<n;
}
void up(int y){
    int dir = 0;
    int nx = n-1;
    int ny = y;
    int timer = 1;
    int num = arr[nx][ny];

    while(InRange(nx,ny)){
        if(num==1){
            if(dir==0)
                dir = 1;
            else if(dir==1)
                dir = 0;
            else if(dir==2)
                dir = 3;
            else if(dir==3)
                dir = 2;
        }
        else if(num==2){
            if(dir==0)
                dir = 3;
            else if(dir==1)
                dir = 2;
            else if(dir==2)
                dir = 1;
            else if(dir==3)
                dir = 0;
        }
        nx = nx + dx[dir];
        ny = ny + dy[dir];
        num = arr[nx][ny];
        timer++;
    }
    ans = max(ans, timer);
}

void down(int y){
    int dir = 2;
    int nx = 0;
    int ny = y;
    int timer = 1;
    int num = arr[nx][ny];

    while(InRange(nx,ny)){
        timer++;
        if(num==1){
            if(dir==0)
                dir = 1;
            else if(dir==1)
                dir = 0;
            else if(dir==2)
                dir = 3;
            else
                dir = 2;
        }
        else if(num==2){
            if(dir==0)
                dir = 3;
            else if(dir==1)
                dir = 2;
            else if(dir==2)
                dir = 1;
            else
                dir = 0;
        }
        nx = nx + dx[dir];
        ny = ny + dy[dir];
        num = arr[nx][ny];
    }
    ans = max(ans, timer);
}

void right(int x){
    int dir = 1;
    int nx = x;
    int ny = 0;
    int timer = 1;
    int num = arr[nx][ny];

    while(InRange(nx,ny)){
        timer++;
        if(num==1){
            if(dir==0)
                dir = 1;
            else if(dir==1)
                dir = 0;
            else if(dir==2)
                dir = 3;
            else
                dir = 2;
        }
        else if(num==2){
            if(dir==0)
                dir = 3;
            else if(dir==1)
                dir = 2;
            else if(dir==2)
                dir = 1;
            else
                dir = 0;
        }
        nx = nx + dx[dir];
        ny = ny + dy[dir];
        num = arr[nx][ny];
    }
    ans = max(ans, timer);
}

void left(int x){
    int dir = 3;
    int nx = x;
    int ny = n-1;
    int timer = 1;
    int num = arr[nx][ny];

    while(InRange(nx,ny)){
        timer++;
        if(num==1){
            if(dir==0)
                dir = 1;
            else if(dir==1)
                dir = 0;
            else if(dir==2)
                dir = 3;
            else
                dir = 2;
        }
        else if(num==2){
            if(dir==0)
                dir = 3;
            else if(dir==1)
                dir = 2;
            else if(dir==2)
                dir = 1;
            else
                dir = 0;
        }
        nx = nx + dx[dir];
        ny = ny + dy[dir];
        num = arr[nx][ny];
    }
    ans = max(ans, timer);
}

int main() {
    cin>>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0; i<n; i++){
        up(i);
        down(i);
        right(i);
        left(i);
    }

    cout<<ans<<'\n';
    return 0;
}