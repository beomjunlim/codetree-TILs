#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
#include <climits>
using namespace std;

struct Attacker {
    int attk, day, r, c;

    bool operator<(const Attacker& a) const {
        if (attk != a.attk)
            return attk > a.attk;
        if (day != a.day)
            return day < a.day;
        if (r + c != a.r + a.c)
            return r + c < a.r + a.c;
        return c < a.c;
    }
};

struct Defence {
    int attk, day, r, c;

    bool operator<(const Defence& a) const {
        if (attk != a.attk)
            return attk < a.attk;
        if (day != a.day)
            return day > a.day;
        if (r + c != a.r + a.c)
            return r + c > a.r + a.c;
        return c > a.c;
    }
};

int N, M, K;
int Map[11][11];
int Last[11][11];
bool visited[11][11];
pair<int, int> parent[11][11];
int dx[] = { 0,1,0,-1 ,-1,-1,1,1};
int dy[] = { 1,0,-1,0, -1,1,1,-1 };


int main() {
    cin >> N >> M >> K;

    int total = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> Map[i][j];
            Last[i][j] = 0;
            if (Map[i][j] != 0)
                total++;
        }
    }

    int Pluse = N + M;
    for (int k = 1; k <= K; k++) {
        if (total == 1)
            break;

        priority_queue<Attacker> attack;
        priority_queue<Defence> defe;
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (Map[i][j] > 0) {
                    attack.push({ Map[i][j], Last[i][j], i,j });
                    defe.push({ Map[i][j], Last[i][j], i, j });
                }
            }
        }

        int aPower = attack.top().attk;
        int aR = attack.top().r;
        int aC = attack.top().c;

        int bR = defe.top().r;
        int bC = defe.top().c;

        bool laser = false;
        memset(visited, false, sizeof(visited));
        queue<pair<int, int>> q;
        q.push({ aR,aC });
        visited[aR][aC] = true;

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (x == bR && y == bC) {
                laser = true;
                break;
            }

            for (int i = 0; i < 4; i++) {
                int nx = (N + x + dx[i]) % N;
                int ny = (M + y + dy[i]) % M;

    


                if (Map[nx][ny] != 0 && !visited[nx][ny]) {
                    parent[nx][ny] = { x,y };
                    visited[nx][ny] = true;
                    q.push({ nx,ny });
                }
            }
        }
        
        memset(visited, false, sizeof(visited));
        visited[aR][aC] = true;
        visited[bR][bC] = true;
        Map[aR][aC] += Pluse;
        Map[bR][bC] -= Map[aR][aC];
        Last[aR][aC] = k;

        int ace = Map[aR][aC] / 2;

        if (laser) {
            int x = parent[bR][bC].first;
            int y = parent[bR][bC].second;

            while (1) {
                if (x == aR && y == aC)
                    break;

                Map[x][y] -= ace;
                visited[x][y] = true;
                int nx = parent[x][y].first;
                int ny = parent[x][y].second;

                x = nx, y = ny;
            }
        }

        else {
            int x = bR, y = bC;

            for (int i = 0; i < 8; i++) {
                int nx = (N + x + dx[i]) % N;
                int ny = (M + y + dy[i]) % M;

                if (Map[nx][ny] != 0) {
                    visited[nx][ny] = true;
                    if (nx == aR && ny == aC)
                        Map[nx][ny] += ace;
                    Map[nx][ny] -= ace;
                }
            }
        }
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (!visited[i][j] && Map[i][j] > 0) {
                    Map[i][j]++;
                }
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (visited[i][j] && Map[i][j] <= 0) {
                    Map[i][j] = 0;
                    total--;
                }
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            answer = max(answer, Map[i][j]);
        }
    }
    cout << answer;
    return 0;
}