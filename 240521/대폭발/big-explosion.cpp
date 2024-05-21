#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

int n,m;
int ans = 0;
int arr[100][100];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
queue<pair<int,int>> bomb;

bool InRange(int x, int y){
    return 0<=x&&x<n&&0<=y&&y<n;
}

void myFunction(int time){
    int size = bomb.size();
    int next = pow(2, time-1);

    for(int i=0; i<size; i++){
        int x = bomb.front().first;
        int y = bomb.front().second;
        bomb.pop();

        for(int i=0; i<4; i++){
            int nx = (x + next*dx[i]);
            int ny = (y + next*dy[i]);

            if(InRange(nx,ny)&&arr[nx][ny]==0){
                arr[nx][ny] = 1;
                ans++;
                bomb.push(make_pair(nx,ny));
            }
        }
        bomb.push(make_pair(x,y));
    }
}

int main() {
    int r,c;
    cin>>n>>m>>r>>c;
    
    arr[r-1][c-1] = 1;
    bomb.push(make_pair(r-1,c-1));
    ans++;

    for(int i=1; i<=m; i++){
        myFunction(i);
    }

    cout<<ans<<'\n';
    return 0;
}