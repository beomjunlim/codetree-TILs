#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int R,C,K;
vector<pair<int,int>> monster;
int arr[75][75];
bool Exit[75][75];
bool visited[75][75];
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

void clearMap(){
    for(int i=0; i<=R; i++){
        for(int j=0; j<=C; j++){
            arr[i][j] = 0;
            Exit[i][j] = false;
        }
    }
}

bool GoA(int x, int y){
    if(x==R||y<2||y>=C)
        return false;
    
    int a = arr[x][y-1];
    int b = arr[x][y+1];
    int c = arr[x+1][y];

    if(a==0&&b==0&&c==0)
        return true;
    return false;
}

bool GoB(int x, int y){
    if(x==R||y<3)
        return false;
    
    int a = arr[x-2][y-1];
    int b = arr[x-1][y-2];
    int c = arr[x][y-1];

    if(a==0&&b==0&&c==0){
        int nx = x;
        int ny = y - 1;
        if(GoA(nx,ny))
            return true;
        return false;
    }
    return false;
}

bool GoC(int x, int y){
    if(x==R||y>C-2)
        return false;
    
    int a = arr[x-2][y+1];
    int b = arr[x-1][y+2];
    int c = arr[x][y+1];

    if(a==0&&b==0&&c==0){
        int nx = x;
        int ny = y + 1;
        if(GoA(nx,ny))
            return true;
        return false;
    }
    return false;
}

int bfs(int x, int y){
    memset(visited, false, sizeof(visited));
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    visited[x][y] = true;

    int max_x = x - 3;

    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        max_x = max(max_x, cx - 3);

        int num = arr[cx][cy];
        bool sw = Exit[cx][cy];

        for(int i=0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if(!visited[nx][ny]&&arr[nx][ny]!=0){
                if(sw||num==arr[nx][ny]){
                    visited[nx][ny] = true;
                    q.push(make_pair(nx,ny));
                }
            }
        }
    }
    return max_x;
}

int main() {
    int ans = 0;
    cin>>R>>C>>K;
    R = R + 3;
    for(int i=1; i<=K; i++){
        int c,d;
        cin>>c>>d;
        
        int x = 2;
        int y = c;

        while(1){
            if(GoA(x,y)){
                x++;
            }
            else if(GoB(x,y)){
                x++;
                y--;
                d = (d+3)%4;
            }
            else if(GoC(x,y)){
                x++;
                y++;
                d = (d+1)%4;
            }
            else
                break;
        }

        if(x<=4){
            clearMap();
        }
        else{
            int cx = x - 1;
            int cy = y;
            arr[cx][cy] = i*2;

            for(int j=0; j<4; j++){
                int nx = cx + dx[j];
                int ny = cy + dy[j];

                if(j==d){
                    Exit[nx][ny] = true;
                }
                arr[nx][ny] = i*2;
            }
            ans += bfs(cx + dx[d], cy + dy[d]);
        }   
    }
    cout<<ans;
    return 0;
}