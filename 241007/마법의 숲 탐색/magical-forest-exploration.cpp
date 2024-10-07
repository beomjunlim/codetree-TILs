#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <climits>
#include <cstring>
using namespace std;

int R, C,K;
int answer = 0;
int arr[74][74];
bool visited[74][74];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

bool InRange(int x, int y) {
    return 0 <= x && x <= R + 3 && 1 <= y && y <= C;
}

int bfs(int a, int b, int K) {
    memset(visited, false, sizeof(visited));
    queue<pair<int, int>> q;
    q.push({ a,b });
    visited[a][b] = true;
    int low_x = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        //if(K==1)
            //cout<<x-3<<" "<<y<<'\n';
        int num = arr[x][y];
        int sub = 0;
        if(num>0)
            sub = num/5; 

        low_x = max(low_x, x);


        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (InRange(nx, ny) && !visited[nx][ny]) {
                if(num<0){
                    if(arr[nx][ny]!=0){
                        visited[nx][ny] = true;
                        q.push({nx,ny});
                    }
                }
                else{
                    if(arr[nx][ny]==num||arr[nx][ny]==-2*sub){
                        visited[nx][ny] = true;
                        q.push({nx,ny});
                    }
                }
                
            }
        }
    }
    return low_x - 3;
}

void Reset() {
    for (int i = 0; i < 74; i++) {
        for (int j = 0; j < 74; j++) {
            arr[i][j] = 0;
        }
    }
}

bool Down(int x, int y) {
    if (InRange(x+2,y)&&arr[x + 2][y] == 0 && arr[x+1][y - 1] == 0 && arr[x+1][y + 1] == 0)
        return true;
    return false;
}

bool West(int x, int y) {
    if (InRange(x+1,y-2)&&arr[x - 1][y - 1] == 0 && arr[x][y - 2]==0 && arr[x + 1][y - 1]==0) {
        if (InRange(x+2,y-1)&&arr[x+2][y-1]==0&&arr[x+1][y-2]==0)
            return true;
    }
    return false;
}

bool East(int x, int y) {
    if (InRange(x+1,y+2)&&arr[x - 1][y + 1] == 0 && arr[x][y + 2] == 0 && arr[x + 1][y + 1] == 0) {
        if (InRange(x+2,y+1)&&arr[x+2][y+1]==0&&arr[x+1][y+2]==0)
            return true;
    }
    return false;
}

void clean(int x, int y) {
    arr[x][y] = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        arr[nx][ny] = 0;
    }
}

void fill(int x, int y, int k) {
    arr[x][y] = 5*k;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        arr[nx][ny] = 5*k;
    }
}

bool check() {
    for (int i = 1; i <=3; i++) {
        for (int j = 1; j <= C; j++) {
            if (arr[i][j] !=0)
                return false;
        }
    }
    return true;
}


int main() {
    cin >> R >> C >> K;
    K++;
    while (K > 1) {
        int c, d;
        cin >> c >> d;
        K--;
        int x = 1;
        int y = c;

        fill(x, y,K);

        while (1) {
            if (Down(x, y)) { 
                clean(x,y);
                x++;
                fill(x, y,K);
                arr[x + dx[d]][y + dy[d]] = -2*K;
            }
            else {
                if (West(x, y)) {
                    d = (d + 3) % 4;
                    clean(x, y);
                    x++;
                    y--;
                    fill(x, y,K);
                    arr[x + dx[d]][y + dy[d]] = -2*K;
                }
                else if (East(x, y)) {
                    d = (d + 1) % 4;
                    clean(x, y);
                    x++;
                    y++;
                    fill(x, y,K);
                    arr[x + dx[d]][y + dy[d]] = -2*K;
                }
                else {
                    if (check()) {
                        // for(int i=4; i<=R+3; i++){
                        //     for(int j=1; j<=C; j++){
                        //         cout<<arr[i][j]<<" ";
                        //     }
                        //     cout<<'\n';
                        // }
                        // cout<<"=================="<<'\n';
                       //  if(K==1){
                        //      for(int i=4; i<=R+3; i++){
                        //     for(int j=1; j<=C; j++){
                        //         cout<<arr[i][j]<<" ";
                        //     }
                        //     cout<<'\n';
                        // }
                        //  }
                        int num = bfs(x,y,K);

                        answer += num;
                    }
                    else {
                        Reset();
                    }
                    break;
                }
            }
        }
    }
    cout << answer;
    return 0;
}