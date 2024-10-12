#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <cmath>
#include <cstring>
#include <climits>
using namespace std;

struct Santa {
    int r, c, score, sturn;
    bool dead;
};

int N,M,P,C,D;
int X, Y;
int SantaNum = 0;
Santa santa[31];
int Map[51][51];
int dearX[] = {-1,-1,-1,0,1,1,1,0};
int dearY[] = {-1,0,1,1,1,0,-1,-1};

bool InRange(int x, int y) {
    return 0 < x && x <= N && 0 < y && y <= N;
}

void Interaction(int id, int dir) {
    queue<int> q;
    q.push(id);

    while (!q.empty()) {
        int Id = q.front();
        q.pop();

        santa[Id].r += dearX[dir];
        santa[Id].c += dearY[dir];
        
        int x = santa[Id].r;
        int y = santa[Id].c;
        
        if (!InRange(x, y)) {
            SantaNum--;
            santa[Id].dead = true;
            break;
        }

        int idx = Map[x][y];
        Map[x][y] = Id;

        if (idx != 0)
            q.push(idx);        
    }
}

void smash(int id, int dir, int score) {
    santa[id].r += score*dearX[dir];
    santa[id].c += score * dearY[dir];
    santa[id].score += score;

    if (!InRange(santa[id].r, santa[id].c)) {
        SantaNum--;
        santa[id].dead = true;
        return;
    }

    int Id = Map[santa[id].r][santa[id].c];
    Map[santa[id].r][santa[id].c] = id;

    if (Id != 0) {
        Interaction(Id, dir);
    }
}

int main() {
    cin >> N >> M >> P >> C >> D;
    cin >> X >> Y;

    SantaNum = P;

    for (int i = 1; i <= P; i++) {
        int id, x, y;
        cin >> id >> x >> y;
        Map[x][y] = id;
        santa[id] = { x,y,0,-1,false };
    }

    for (int m = 1; m <= M; m++) {
        if (SantaNum == 0)
            break;

        int id;
        int dist = INT_MAX;
        int r = -1, c = -1;
        int Dir;
        for (int i = 1; i <= P; i++) {
            if (santa[i].dead)
                continue;

            int x = santa[i].r;
            int y = santa[i].c;

            int num = pow(X - x, 2) + pow(Y - y, 2);
            if (num <= dist) {
                if (num < dist) {
                    dist = num;
                    r = x, c = y, id = i;
                }
                else {
                    if (r < x) {
                        r = x, c = y, id = i;
                    }
                    else if (r == x) {
                        if (c < y) {
                            c = y, id = i;
                        }
                    }
                }
            }
        }

        if (r < X && c < Y)
            Dir = 0;
        else if (r < X && c == Y)
            Dir = 1;
        else if (r<X && c>Y)
            Dir = 2;
        else if (r == X && c > Y)
            Dir = 3;
        else if (r > X && c > Y)
            Dir = 4;
        else if (r > X && c == Y)
            Dir = 5;
        else if (r > X && c < Y)
            Dir = 6;
        else if (r == X && c < Y)
            Dir = 7;

        X += dearX[Dir];
        Y += dearY[Dir];
        
        int Id = Map[X][Y];

        if (Id != 0) {
            Map[X][Y] = 0;
            santa[Id].sturn = m; // 기절 업데이트
            smash(Id, Dir, C); // 충돌
        }

        // 산타 움직임
        for (int i = 1; i <= P; i++) {
            if (santa[i].dead)
                continue;
            if (santa[i].sturn == m || santa[i].sturn == m - 1)
                continue;

            int dx[] = { -1,0,1,0 };
            int dy[] = { 0,1,0,-1 };
            int x = santa[i].r, y = santa[i].c;
            int dis = pow(X - x,2) + pow(Y - y,2);
            int dir = -1;
            for (int j = 0; j < 4; j++) {
                int nx = x + dx[j];
                int ny = y + dy[j];
                int Dis = pow(X - nx, 2) + pow(Y - ny, 2);

                if (!InRange(nx, ny)||Map[nx][ny]!=0)
                    continue;

                if (Dis < dis) {
                    dir = j;
                    dis = Dis;
                }
            }

            if (dir == -1)
                continue;

            Map[x][y] = 0;
            x += dx[dir];
            y += dy[dir];
            
            santa[i].r = x;
            santa[i].c = y;
            Map[x][y] = i;

            if (x == X && y == Y) {
                Map[x][y] = 0;
                if (dir == 0)
                    dir = 5;
                else if (dir == 3)
                    dir = 7;
                else if (dir == 2)
                    dir = 3;
                santa[i].sturn = m;
                smash(i, dir,D);
            }
        }

        for (int i = 1; i <= P; i++) {
            if (!santa[i].dead)
                santa[i].score++;
        }
    }
    
    for (int i = 1; i <= P; i++)
        cout << santa[i].score << " ";
    return 0;
}