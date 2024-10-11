#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <unordered_map>
#include <cstring>
#include <climits>
using namespace std;


int n, m;
int Map[16][16];
int cnt[16][16];
pair<int, int> people[31];
pair<int, int> mart[31];
bool visited[16][16];
int dx[] = { -1,0,0,1 };
int dy[] = { 0,-1,1,0 };


bool InRange(int x, int y) {
    return 0 < x && x <= n && 0 < y && y <= n;
}

void bfs(int idx) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cnt[i][j] = 0;
        }
    }
    memset(visited, false, sizeof(visited));
    queue<pair<int, int>> q;
    q.push({ mart[idx].first, mart[idx].second });
    visited[mart[idx].first][mart[idx].second] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (InRange(nx, ny) && !visited[nx][ny] && Map[nx][ny] != -1) {
                visited[nx][ny] = true;
                cnt[nx][ny] = cnt[x][y] + 1;
                q.push({ nx,ny });
            }
        }
    }
}

void GoBase(int time) {
    bfs(time);

    int min_dist = INT_MAX;
    int mx = -1, my = -1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (visited[i][j] && Map[i][j] == 1 && min_dist > cnt[i][j]) {
                min_dist = cnt[i][j];
                mx = i;
                my = j;
            }
        }
    }

    people[time] = { mx,my };
    Map[mx][my] = -1;
}

int main() {
    cin >> n >> m;

    int idx = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> Map[i][j];
        }
    }

    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        mart[i] = { x,y };
        people[i] = { -1,-1 };
    }

    int Escape = m;
    int time = 1;
    while (1) {
        for (int i = 1; i <= m; i++) {
            if (people[i] == make_pair(-1, -1) || people[i] == mart[i])
                continue;
            bfs(i);

            int x = people[i].first;
            int y = people[i].second;

            int min_dist = INT_MAX;
            int mx = -1, my = -1;
            for (int j = 0; j < 4; j++) {
                int nx = x + dx[j];
                int ny = y + dy[j];

                if (InRange(nx, ny) && visited[nx][ny] && min_dist > cnt[nx][ny]) {
                    min_dist = cnt[nx][ny];
                    mx = nx;
                    my = ny;
                }
            }

            people[i] = { mx,my };
            if (people[i] == mart[i])
                Escape--;
        }

        for (int i = 1; i <= m; i++) {
            if (people[i] == mart[i]) {
                Map[mart[i].first][mart[i].second] = -1;
            }
        }

        if (time <= m)
            GoBase(time);
        if (Escape == 0)
            break;
        time++;
    }

    cout << time << '\n';
    return 0;
}