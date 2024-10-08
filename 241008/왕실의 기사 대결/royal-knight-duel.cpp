#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>
#include <queue>
using namespace std;

struct Knight {
    int r, c, h, w, k;
};

int L, N, Q;
int arr[41][41];
bool moving[31];
Knight knight[31];
int answer[31];
int damage[31];
int nr[31];
int nc[31];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };


bool InRange(int x, int y) {
    return 0 < x && x <= L && 0 < y && y <= L;
}

bool CanMove(int idx, int dir) {
    memset(moving, false, sizeof(moving));
    queue<int> q;
    q.push(idx);
    moving[idx] = true;

    for (int i = 1; i <= N; i++) {
        nr[i] = knight[i].r;
        nc[i] = knight[i].c;
        damage[i] = 0;
    }

    while (!q.empty()) {
        int ID = q.front();
        q.pop();

        nr[ID] += dx[dir];
        nc[ID] += dy[dir];
        int h = knight[ID].h;
        int w = knight[ID].w;
        if (!InRange(nr[ID], nc[ID]) || !InRange(nr[ID] + h - 1, nc[ID] + w - 1))
            return false;

        for (int i = nr[ID]; i < nr[ID] + h; i++) {
            for(int j = nc[ID]; j < nc[ID] + w; j++) {
                if (arr[i][j] == 2){
                    return false;
                }
                if (arr[i][j] == 1){
                    damage[ID]++;
                }
            }
        }

        for (int i = 1; i <= N; i++) {
            if (moving[i] || knight[i].k <= 0)
                continue;
            if (knight[i].r + knight[i].h - 1 < nr[ID] || knight[i].r > nr[ID] + h - 1)
                continue;
            if (knight[i].c + knight[i].w - 1 < nc[ID] || knight[i].c > nc[ID] + w - 1)
                continue;
            

            moving[i] = true;
            q.push(i);
        }
    }

    damage[idx] = 0;
    return true;
}

void MovePiece(int idx, int dir) {
    if (knight[idx].k <= 0)
        return;
    
    if (CanMove(idx, dir)) {
        for (int id = 1; id <= N; id++) {
            knight[id].r = nr[id];
            knight[id].c = nc[id];
            knight[id].k -= damage[id];
            answer[id] += damage[id];

            if (knight[id].k <= 0)
                answer[id] = 0;
        }
    }
}

int main() {
    cin >> L >> N >> Q;

    for (int i = 1; i <= L; i++) {
        for (int j = 1; j <= L; j++) {
            cin >> arr[i][j];
        }
    }

    for (int n = 1; n <= N; n++) {
        cin >> knight[n].r >> knight[n].c >> knight[n].h >> knight[n].w >> knight[n].k;
    }

    while (Q > 0) {
        int idx, d;
        cin >> idx >> d;
        MovePiece(idx, d);
        Q--;
    }

    long long ans = 0;
    for (int i = 1; i <= N; i++){
            ans += answer[i];
    }
    

    cout << ans;
    
    return 0;
}