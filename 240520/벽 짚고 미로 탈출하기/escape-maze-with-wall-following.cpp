#include <iostream>
using namespace std;

int n;
int ans;
char arr[100][100];
bool visited[100][100][4];
int dx[] = {0,1,0,-1}; // > V < ^
int dy[] = {1,0,-1,0};
int dir = 0;

bool InRange(int x, int y){
    return 0<=x&&x<n&&0<=y&&y<n;
}

void simulation(int x, int y, int dir, int cnt, bool sw){
    if(!InRange(x,y)){
        ans = cnt;
        return;
    }

    if(visited[x][y][dir]){
        ans = -1;
        return;
    }

    visited[x][y][dir] = true;

    int nx = x + dx[dir];
    int ny = y + dy[dir];

    if(InRange(nx,ny)&&arr[nx][ny]=='#'){
        dir = (dir+3)%4;
        simulation(x, y, dir, cnt,0);
    }
    else{
        int right_x = nx + dx[(dir+1)%4];
        int right_y = ny + dy[(dir+1)%4];

        if(sw){
            simulation(nx,ny, dir, cnt+1,0);
        }

        else if(InRange(right_x, right_y)&&arr[right_x][right_y]=='#'){
            simulation(nx,ny,dir,cnt+1,0);
        }
        else{
            simulation(nx, ny, (dir+1)%4,cnt+1,1);
        }
    }
}

int main() {
    int x, y;
    cin>>n>>x>>y;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    x = x -1;
    y = y -1;

    simulation(x,y,0,0,0);

    cout<<ans<<'\n';


    return 0;
}