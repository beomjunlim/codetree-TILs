#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;

struct Knight {
    int r, c, h, w, k, damage;
};

int L, N, Q;
int arr[41][41];
int knightMap[41][41];
int temp[41][41];
bool Dead[31];
bool visited[31];
Knight knight[31];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

bool InRange(int x, int y) {
    return 0 < x && x <= L && 0 < y && y <= L;
}

bool CanGo(int idx, int d, vector<int>& v, int Q) {
    int x = knight[idx].r;
    int y = knight[idx].c;
    int h = knight[idx].h;
    int w = knight[idx].w;

    // 이동할 범위가 맵을 벗어나는지 확인
    if (!InRange(x + dx[d], y + dy[d]) || !InRange(x + h - 1 + dx[d], y + w - 1 + dy[d])) {
        return false;
    }

    int nx = x + dx[d];
    int ny = y + dy[d];

    // 이동할 위치에 장애물이 있거나 다른 기사가 있는지 확인
    for (int i = nx; i < nx + h; i++) {
        for (int j = ny; j < ny + w; j++) {
            if (arr[i][j] == 2) { // 장애물이 있는 경우
                return false;
            }

            if (knightMap[i][j] != 0 && knightMap[i][j] != idx && !Dead[knightMap[i][j]]) {
                // 다른 기사가 있을 때, 그 기사를 먼저 이동 가능 여부를 재귀적으로 확인
                if (!CanGo(knightMap[i][j], d, v, Q)) {
                    return false;
                }
            }
        }
    }

    // 기사가 이동 가능하다면 목록에 추가
    if (!visited[idx]) {
        visited[idx] = true;
        v.push_back(idx);
    }
    return true;
}

int main() {
    cin >> L >> N >> Q;

    // 맵 입력
    for (int i = 1; i <= L; i++) {
        for (int j = 1; j <= L; j++) {
            cin >> arr[i][j];
        }
    }

    // 기사 정보 입력
    for (int n = 1; n <= N; n++) {
        int r, c, h, w, k;
        cin >> r >> c >> h >> w >> k;
        knight[n] = { r, c, h, w, k, 0 }; // 초기 위치와 정보
        for (int i = r; i < r + h; i++) {
            for (int j = c; j < c + w; j++) {
                knightMap[i][j] = n;
            }
        }
    }

    // 이동 명령 처리
    while (Q > 0) {
        int idx, d;
        cin >> idx >> d;
        vector<int> carry; // 이동할 기사 목록

        if (Dead[idx])
            continue;
        memset(visited, false, sizeof(visited));

        // 이동 가능하면 처리
        if (CanGo(idx, d, carry, Q)) {
            for (int id = 0; id < carry.size(); id++) {
                int Id = carry[id];
                int x = knight[Id].r;
                int y = knight[Id].c;
                int h = knight[Id].h;
                int w = knight[Id].w;
                int k = knight[Id].k;
                int damage = knight[Id].damage;

                int nx = x + dx[d];
                int ny = y + dy[d];

                int attack = 0;
                for (int i = nx; i < nx + h; i++) {
                    for (int j = ny; j < ny + w; j++) {
                        temp[i][j] = Id;
                        if (arr[i][j] == 1) {
                            attack++;
                        }
                    }
                }

                if (Id != idx) {
                    k -= attack;
                    if (k <= 0) {
                        Dead[Id] = true;
                    }
                }

                if (Id == idx) {
                    attack = 0;
                }
                knight[Id] = { nx, ny, h, w, k, damage + attack };
            }

            // knightMap 업데이트
            memset(knightMap, 0, sizeof(knightMap));
            for (int id = 1; id <= N; id++) {
                if (!Dead[id]) {
                    int x = knight[id].r;
                    int y = knight[id].c;
                    int h = knight[id].h;
                    int w = knight[id].w;

                    for (int i = x; i < x + h; i++) {
                        for (int j = y; j < y + w; j++) {
                            knightMap[i][j] = id;
                        }
                    }
                }
            }
        }

        Q--;
    }

    int answer = 0;
    for (int i = 1; i <= N; i++) {
        if (!Dead[i]) {
            answer += knight[i].damage;
        }
    }

    cout << answer;
    return 0;
}