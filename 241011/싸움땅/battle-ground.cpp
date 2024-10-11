#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <cmath>
using namespace std;

struct People {
    int x, y, d, s, gun,score;
};

int n, m, k;
priority_queue<int> Gun[21][21];
int person[21][21];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
People people[31];

bool InRange(int x, int y) {
    return 0 < x && x <= n && 0 < y && y <= n;
}

void Defeat(int idx) {
    int x = people[idx].x, y = people[idx].y;
    int dir = people[idx].d;
    int gun = people[idx].gun;
    if (gun != 0)
        Gun[x][y].push(gun);

    people[idx].gun = 0;

    int nx = x + dx[dir];
    int ny = y + dy[dir];

    while (1) {
        if (InRange(nx, ny) && person[nx][ny] == 0)
            break;

        dir = (dir + 1) % 4;
        nx = x + dx[dir];
        ny = y + dy[dir];
    }

    if (!Gun[nx][ny].empty()) {
        gun = Gun[nx][ny].top();
        Gun[nx][ny].pop();
        people[idx].gun = gun;
    }

    person[nx][ny] = idx;
    people[idx].x = nx;
    people[idx].y = ny;
    people[idx].d = dir;
}

void Victory(int idx, int x, int y, int score) {
    Gun[x][y].push(people[idx].gun);
    int gun = Gun[x][y].top();
    Gun[x][y].pop();

    person[x][y] = idx; // 좌표 업데이트
    people[idx].gun = gun; // 총 업그레이드
    people[idx].score += score;
}

void fight(int A, int B) {
    int x = people[A].x;
    int y = people[A].y;
    int Adir = people[A].d;
    int As = people[A].s;
    int Agun = people[A].gun;

    int Bdir = people[B].d;
    int Bs = people[B].s;
    int Bgun = people[B].gun;

    person[x][y] = 0;
    int score = abs((As + Agun) - (Bs + Bgun));

    if ((Agun + As > Bgun + Bs) || ((Agun + As == Bgun + Bs) && As > Bs)) { // A 승
        Defeat(B);
        Victory(A, x, y, score);

    }
    else { // B 승
        Defeat(A);
        Victory(B, x, y, score);
    }
}

int main() {
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int num;
            cin >> num;
            Gun[i][j].push(num);
        }
    }

    for (int i = 1; i <= m; i++) {
        int x, y, d, s;
        cin >> x >> y >> d >> s;
        person[x][y] = i;
        people[i] = { x,y,d,s, 0, 0 };
    }

    while (k--) {
        for (int i = 1; i <= m; i++) {
            int x = people[i].x;
            int y = people[i].y;
            int dir = people[i].d;
            int score = people[i].s;

            if (!InRange(x + dx[dir], y + dy[dir])) {
                dir = (dir + 2) % 4;
                people[i].d = dir;
            }

            int nx = x + dx[dir];
            int ny = y + dy[dir];

            people[i].x = nx;
            people[i].y = ny; // 이동
            person[x][y] = 0; // 이동 전 초기화

            if (person[nx][ny] != 0) {
                fight(i, person[nx][ny]);
            }
            else {
                person[nx][ny] = i;
                int gun = people[i].gun;
                if(gun!=0)
                    Gun[nx][ny].push(gun);

                if (!Gun[nx][ny].empty()){
                    gun = Gun[nx][ny].top();
                    Gun[nx][ny].pop();
                }

                people[i].gun = gun;
            }
        }
    }

    for (int i = 1; i <= m; i++) {
        cout << people[i].score << " ";
    }
    // cout<<'\n';
    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=n; j++){
    //         cout<<person[i][j]<<" ";
    //     }
    //     cout<<'\n';
    // }

    // for(int i=1; i<=m; i++){
    //     cout<<people[i].gun<<" ";
    // }
    return 0;
}