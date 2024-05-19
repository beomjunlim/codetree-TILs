#include <iostream>
using namespace std;

int n;
bool sw;
int ans;
char arr[100][100];
bool visited[100][100][4];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int dir = 0;

bool InRange(int x, int y){
    return 0<=x&&x<n&&0<=y&&y<n;
}

void simulation(int x, int y, int dir, int cnt){
    if(!InRange(x,y)){
        sw = true;
        ans = cnt;
        return;
    }

    if(visited[x][y][dir]){
        sw = false;
        return;
    }

    visited[x][y][dir] = true;

    int right_x = x + dx[(dir+1)%4];
    int right_y = y + dy[(dir+1)%4];
    int nx = x + dx[dir];
    int ny = y + dy[dir];

    if(InRange(right_x,right_y)&&arr[right_x][right_y]=='#'){
        if(InRange(nx,ny)&&arr[nx][ny]=='#')
            simulation(x,y, (dir+1)%4, cnt);
        else
            simulation(nx,ny, dir, cnt+1);
    }

    else{
        dir = (dir+1)%4;
        nx = x + dx[dir];
        ny = y + dy[dir];
        if(InRange(nx,ny)&&arr[nx][ny]=='#')
            simulation(x,y, dir, cnt);
        else{
            if(!visited[nx][ny][(dir+2)%4])
                simulation(nx,ny,dir,cnt+1);
            else
                simulation(x,y, (dir+1)%4, cnt);
        }

    }

    // int nx = x + dx[dir];
    // int ny = y + dy[dir];

    // if(InRange(nx,ny)&&arr[nx][ny]=='#'){
    //     simulation(x,y, (dir+1)%4, cnt);
    // }
    // else{
    //     int right_x = x + dx[(dir+1)%4];
    //     int right_y = y + dy[(dir+1)%4];

    //     if(InRange(right_x,right_y)&&arr[right_x][right_y]=='#'){
    //         simulation(nx,ny, dir, cnt+1);
    //     }
    //     else{
    //         dir = (dir+1)%4;
    //         nx = x + dx[dir];
    //         ny = y + dy[dir];
    //         simulation(nx,ny,dir,cnt+1);
    //     }
    // }

    // int check_x = x + dx[(dir+1)%4];
    // int check_y = y + dy[(dir+1)%4];

    // if(InRange(check_x, check_y)&&arr[check_x][check_y]=='#'){
    //     int nx = x + dx[dir];
    //     int ny = y + dy[dir];
    //     if(arr[nx][ny]=='#'){
    //         dir = (dir+1)%4;
    //         simulation(x,y, dir, cnt);
    //     }
    //     else{
    //         simulation(nx,ny, dir, cnt+1);
    //     }
    // }

    // else{
    //     int nx = x + dx[dir];
    //     int ny = y + dy[dir];
    //     if(InRange(nx,ny)&&arr[nx][ny]=='#'){
    //         dir = (dir+1)%4;
    //         simulation(x,y, dir, cnt);
    //     }
    //     else{
    //         dir = (dir+1)%4;
    //         simulation(nx,ny, dir, cnt+1);
    //     }
    // }
}

int main() {
    sw = false;
    int x, y;
    cin>>n>>x>>y;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    x = x -1;
    y = y -1;

    simulation(x,y,0,0);

    if(sw)
        cout<<ans<<'\n';
    else
        cout<<-1<<'\n';

    return 0;
}