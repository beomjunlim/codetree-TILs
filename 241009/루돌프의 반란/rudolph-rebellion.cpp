#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>
#include <queue>
#include <map>
#include <cmath>
using namespace std;

struct Santa {
    int x, y, score;
    bool dead = false;
    int sturn = -1;
};

Santa santa[31];
int n, m, p, c, d;
int X, Y;
int SantaNum;
int Map[51][51];
int dist[31];
int dx[] = { -1,0,1,0, -1,-1,1,1 };
int dy[] = { 0,1,0,-1,-1,1,-1,1 };


bool InRange(int x, int y) {
    return 0 < x && x <= n && 0 < y && y <= n;
}

void checkDist() {
    for (int i = 1; i <= p; i++) {
        if (!santa[i].dead)
            dist[i] = pow(X - santa[i].x, 2) + pow(Y - santa[i].y, 2);
        else
            dist[i] = INT_MAX;
    }
}

int MoveDear() {
    int dir = -1;
    int dis = 2 * pow(n, 2);
    priority_queue<pair<int, pair<int, int>>> pq;

    for (int i = 1; i <= p; i++) {
        if (dis > dist[i]) {
            dis = dist[i];
            pq = priority_queue<pair<int, pair<int, int>>>();
            pq.push(make_pair(-dist[i], make_pair(santa[i].x, santa[i].y)));
        }
        else if (dis == dist[i] && !pq.empty()) {
            pq.push(make_pair(-dist[i], make_pair(santa[i].x, santa[i].y)));
        }
    }

    dir = -1;
    int tmp = dis;
    int x = pq.top().second.first;
    int y = pq.top().second.second;
    for (int i = 0; i < 8; i++) {
        int nx = X + dx[i];
        int ny = Y + dy[i];

        if (tmp > pow(x - nx, 2) + pow(y - ny, 2)) {
            dir = i;
            tmp = pow(x - nx, 2) + pow(y - ny, 2);
        }
    }

    return dir;
}

void interaction(int ID, int dir) {
    queue<int> q;
    q.push(ID);

    while (!q.empty()) {
        int idx = q.front();
        q.pop();

        int x = santa[idx].x + dx[dir];
        int y = santa[idx].y + dy[dir];

        if (!InRange(x, y)) {
            santa[idx].dead = true;
            SantaNum--;
            break;
        }

        if (Map[x][y] != 0) {
            q.push(Map[x][y]);
        }

        santa[idx].x = x;
        santa[idx].y = y;
        Map[x][y] = idx;
    }
}

void smash(int ID, int dir, int score) {
    santa[ID].score += score;
    santa[ID].x += score * dx[dir];
    santa[ID].y += score * dy[dir];

    if (!InRange(santa[ID].x, santa[ID].y)) {
        santa[ID].dead = true;
        SantaNum--;
        return;
    }

    if (Map[santa[ID].x][santa[ID].y] != 0) {
        int idx = Map[santa[ID].x][santa[ID].y];
        interaction(idx, dir);
    }

    Map[santa[ID].x][santa[ID].y] = ID;
}

int main() {
    cin >> n >> m >> p >> c >> d;
    cin >> X >> Y;

    SantaNum = p;
    Map[X][Y] = -1;

    for (int i = 1; i <= p; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        santa[x] = { y,z,0,false,-1 };
    }

    for (int Q = 1; Q <= m; Q++) {
        if (SantaNum == 0)
            break;

        checkDist();
        int dir = MoveDear();

        Map[X][Y] = 0;
        X += dx[dir];
        Y += dy[dir];

        if (Map[X][Y] != 0) {
            santa[Map[X][Y]].sturn = Q;
            smash(Map[X][Y], dir, c);
        }

        Map[X][Y] = -1;

        for (int i = 1; i <= p; i++) {
            if (santa[i].dead)
                continue;
            if (santa[i].sturn == Q || santa[i].sturn + 1 == Q)
                continue;

            int x = santa[i].x, y = santa[i].y;
            int dis = pow(X - x, 2) + pow(Y - y, 2);
            dir = -1;
            for (int j = 0; j < 4; j++) {
                int nx = x + dx[j];
                int ny = y + dy[j];
                int num = pow(X - nx, 2) + pow(Y - ny, 2);
                if (!InRange(nx, ny))
                    continue;
                if (Map[nx][ny] >= 1 && Map[nx][ny] <= p)
                    continue;

                if (dis > num) {
                    dis = num;
                    dir = j;
                }
            }
            if (dir == -1)
                continue;

            Map[x][y] = 0;
            x += dx[dir];
            y += dy[dir];

            if (Map[x][y] == -1) {
                santa[i].sturn = Q;
                santa[i].x = X;
                santa[i].y = Y;
                dir = (dir + 2) % 4;
                smash(i, dir, d);
            }
            else {
                Map[x][y] = i;
                santa[i].x = x;
                santa[i].y = y;
            }
        }

        for (int i = 1; i <= p; i++) {
            if (!santa[i].dead)
                santa[i].score++;
        }
    }

    for (int i = 1; i <= p; i++) {
        cout << santa[i].score << " ";
    }
    return 0;
}