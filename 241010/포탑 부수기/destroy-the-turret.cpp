#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

struct Attacker {
    int  r, c, power, last;
    
    bool operator<(const Attacker& a) const {
        if (power != a.power)
            return power > a.power;
        if (last != a.last)
            return last < a.last;
        if (r + c != a.r + a.c)
            return r + c < a.r + a.c;
        return c < a.c;
    }
};

struct Defence {
    int r,c, power, last;

    bool operator<(const Defence& a) const {
        if (power != a.power)
            return power < a.power;
        if (last != a.last)
            return last > a.last;
        if (r + c != a.r + a.c)
            return r + c > a.r + a.c;
        return c > a.c;
    }
};

struct BackUP {
    int x, y;
};


int N, M, K;
int towerNum = 0;
int arr[11][11];
int Last[11][11];
BackUP backup[11][11];
bool visited[11][11];
int dx[] = { 0,1,0,-1, 1,1,-1,-1 };
int dy[] = { 1,0,-1,0, -1,1,-1,1 };

int main() {
    cin >> N >> M >> K;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            Last[i][j] = 0;
            if (arr[i][j] != 0)
                towerNum++;
        }
    }

    for (int k = 1; k <= K; k++) {
        if(towerNum==1)
            break;

        priority_queue<Attacker> attack;
        priority_queue<Defence>defence;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (arr[i][j] > 0) {
                    attack.push({ i,j,arr[i][j], Last[i][j] });
                    defence.push({ i,j,arr[i][j], Last[i][j] });
                }
            }
        }

        int attX = attack.top().r;
        int attY = attack.top().c;
        int attP = attack.top().power + N+M;

        int defX = defence.top().r;
        int defY = defence.top().c;
        int defP = defence.top().power - attP;

        arr[attX][attY] = attP;
        Last[attX][attY] = k;

        attP = attP / 2;

        bool laser = false;
        memset(visited, false, sizeof(visited));

        queue<pair<int, int>> q;
        q.push({ attX, attY });
        visited[attX][attY] = true;

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (x == defX && y == defY) {
                laser = true;
                break;
            }

            for (int i = 0; i < 4; i++) {
                int nx = (N + x + dx[i]) % N;
                int ny = (M + y + dy[i]) % M;

                if (!visited[nx][ny] && arr[nx][ny] > 0) {
                    backup[nx][ny] = { x,y };
                    visited[nx][ny] = true;
                    q.push({ nx,ny });
                }
            }
        }

        memset(visited, false, sizeof(visited));
        visited[attX][attY] = true;
        visited[defX][defY] = true;

        if (laser) {
            int x = backup[defX][defY].x;
            int y = backup[defX][defY].y;

            while (1) {
                if (x == attX && y == attY)
                    break;

                arr[x][y] -= attP;
                visited[x][y] = true;

                if (arr[x][y] <= 0)
                    towerNum;

                int nx = backup[x][y].x;
                int ny = backup[x][y].y;

                x = nx;
                y = ny;
            }
        }
        else {
            int x = defX;
            int y = defY;

            for (int i = 0; i < 8; i++) {
                int nx = (N + x + dx[i]) % N;
                int ny = (M + y + dy[i]) % M;

                if (!visited[nx][ny]&&arr[nx][ny] > 0) {
                    visited[nx][ny] = true;
                    arr[nx][ny] -= attP;
                }
            }
        }

        arr[defX][defY] -= arr[attX][attY];

        if(arr[defX][defY]<=0)
            towerNum--;

        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(!visited[i][j]&&arr[i][j]>0)
                    arr[i][j]++;
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
          //  cout<<arr[i][j]<<" ";
            answer = max(answer, arr[i][j]);
        }
     //   cout<<'\n';
    }

    cout << answer;
    return 0;
}