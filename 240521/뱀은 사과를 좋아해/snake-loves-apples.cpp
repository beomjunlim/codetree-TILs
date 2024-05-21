#include <iostream>
#include <deque>
using namespace std;

int n,m,k;
int timer = 0;
int arr[100][100]; // 0 빈칸 1 뱀 2 사과
int dx[] = {-1,0,1,0}; // U 0 R 1 D 2 L 3
int dy[] = {0,1,0,-1};
deque<pair<int,int>> snake;

bool InRange(int x, int y){
    return 0<=x&&x<n&&0<=y&&y<n;
}

bool moving(int dir, int cnt){
    for(int i=0; i<cnt; i++){
        timer++;
        int nx = snake.front().first + dx[dir];
        int ny = snake.front().second + dy[dir];

        if(InRange(nx,ny)&&arr[nx][ny]!=1){
            if(arr[nx][ny]==0){
                arr[snake.back().first][snake.back().second] = 0;
                snake.pop_back();
            }
            snake.push_front(make_pair(nx,ny));
            arr[nx][ny] = 1;
        }
        else if(InRange(nx,ny)&&arr[nx][ny]==1&&snake.back().first==nx&&snake.back().second==ny){
            snake.pop_back();
            snake.push_front(make_pair(nx,ny));
        }
        else
            return false;
    }
    return true;
}

int main() {
    bool sw = true;
    cin>>n>>m>>k;
    
    snake.push_front(make_pair(0,0));
    arr[0][0] = 1;

    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        arr[a-1][b-1] = 2;
    }

    for(int i=0; i<k; i++){
        char a;
        int b;
        cin>>a>>b;
        int dir;
        if(a=='U')
            dir = 0;
        else if(a=='R')
            dir = 1;
        else if(a=='D')
            dir = 2;
        else if(a=='L')
            dir = 3;
        if(sw){
            if(!moving(dir,b))
                sw = false;
        }
    }

    cout<<timer<<'\n';
    return 0;
}