#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <cmath>
#include <cstring>
#include <climits>
using namespace std;

struct Knight {
    int r, c, h, w, k;
};

int L, N, Q;
int Map[41][41];
Knight knight[31];
long long Damage[31];
bool Dead[31];
bool visited[31];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

bool InRange(int x, int y) {
    return 0 < x && x <= L && 0 < y && y <= L;
}

bool move(int id, int d) {
    queue<int> q;
    q.push(id);
    visited[id] = true;

    while (!q.empty()) {
        int Idx = q.front();
        q.pop();
        
        int r = knight[Idx].r;
        int c = knight[Idx].c;
        int h = knight[Idx].h;
        int w = knight[Idx].w;

        int nr = r + dx[d];
        int nc = c + dy[d];

        if (!InRange(nr, nc) || !InRange(nr + h - 1, nc + w -1))
            return false;

        for (int i = nr; i < nr + h; i++) {
            for (int j = nc; j < nc + w; j++) {
                if (Map[i][j] == 2)
                    return false;
            }
        }

        for (int i = 1; i <= N; i++) {
            if (!visited[i] && !Dead[i]) {
                int x = knight[i].r, y = knight[i].c;
                int dh = knight[i].h, dw = knight[i].w;

                if (x + dh - 1 < nr || nr + h - 1 < x)
                    continue;

                if (y + dw - 1 < nc || nc + w - 1 < y)
                    continue;

                visited[i] = true;
                q.push(i);
            }
        }
    }
    return true;
}

int main() {
    cin >> L >> N >> Q;

    for (int i = 1; i <= L; i++) {
        for (int j = 1; j <= L; j++) {
            cin >> Map[i][j];
        }
    }

    for (int i = 1; i <= N; i++) {
        int r, c, h, w, k;
        cin >> r >> c >> h >> w >> k;
        knight[i] = { r,c,h,w,k };
    }

    while (Q--) {
        int id, d;
        cin >> id >> d;
        if (Dead[id])
            continue;
        memset(visited, false, sizeof(visited));
        if (move(id, d)) {
            for (int i = 1; i <= N; i++) {
                if (!Dead[i] && visited[i]) {
                    knight[i].r += dx[d];
                    knight[i].c += dy[d];

                    int r = knight[i].r;
                    int c = knight[i].c;
                    int h = knight[i].h;
                    int w = knight[i].w;

                    int attack = 0;

                    for (int x = r; x < r + h; x++) {
                        for (int y = c; y < c + w; y++) {
                            if (Map[x][y] == 1)
                                attack++;
                        }
                    }

                    if (i == id)
                        attack = 0;

                    knight[i].k -= attack;
                    Damage[i] += attack;

                    if (knight[i].k <= 0)
                        Dead[i] = true;
                }
            }
        }
    }

    long long answer = 0;
    for (int i = 1; i <= N; i++) {
        if (!Dead[i])
            answer += Damage[i];
    }

    cout << answer;
    return 0;
}