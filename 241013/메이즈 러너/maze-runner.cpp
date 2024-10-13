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

struct People {
    int x, y;
};

struct Rotate {
    int x, y, size;
};

int N, M, K;
int X, Y;
int answer = 0;
int Map[11][11];
map<int, People> people;
bool escape[11];
int PeopleNum = 0;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

bool InRange(int x, int y) {
    return 0 < x && x <= N && 0 < y && y <= N;
}

void move() {
    for (auto& p : people) {
        if(escape[p.first])
            continue;
        int x = p.second.x;
        int y = p.second.y;
        int dist = abs(X - x) + abs(Y - y);
        int nX = -1, nY = -1;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nDist = abs(X - nx) + abs(Y - ny);

            if (InRange(nx, ny) && Map[nx][ny] == 0 && nDist < dist) {
                dist = nDist;
                nX = nx;
                nY = ny;
            }
        }

        if (nX == -1 && nY == -1)
            continue;

        answer++;

        if (nX == X && nY == Y) {
            PeopleNum--;
            escape[p.first] = true;
            people[p.first] = { nX,nY};
        }
        else {
            people[p.first] = { nX,nY};
        }
    }
}

bool CanRotate(int x, int y, int size) {
    if (x <= X && X < x + size && y <= Y && Y < y + size) {
        for (auto p : people) {
            int nx = p.second.x;
            int ny = p.second.y;

            if (x <= nx && nx < x + size && y <= ny && ny < y + size)
                return true;
        }
    }
    return false;
}

Rotate findRotate() {
    for (int s = 2; s <= N; s++) {
        for (int i = 1; i <= N - s + 1; i++) {
            for (int j = 1; j <= N - s + 1; j++) {
                if (CanRotate(i, j, s)) {
                    return { i,j,s };
                }
            }
        }
    }
}


int main() {
    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> Map[i][j];
        }
    }

    for (int i = 1; i <= M; i++) {
        int x, y;
        cin >> x >> y;
        people[i] = { x,y };
    }

    PeopleNum = M;
    cin >> X >> Y;

    while (K--) {
        if (PeopleNum == 0)
            break;

        move();

        for (int i = 1; i <= M; i++) {
            if (escape[i])
                people.erase(i);
        }

        if (people.size()==0)
            break;

        Rotate R = findRotate();
        int temp[11][11];

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                temp[i][j] = Map[i][j];
            }
        }

        int nX = X;
        int nY = Y;

        for (int i = 0; i < R.size; i++) {
            for (int j = 0; j < R.size; j++) {
                if (R.x + R.size - 1 - j == X && R.y + i == Y) {
                    nX = R.x + i;
                    nY = R.y + j;
                }
                if (Map[R.x + R.size - 1 - j][R.y + i] > 0)
                    Map[R.x + R.size - 1 - j][R.y + i]--;
                temp[R.x + i][R.y + j] = Map[R.x + R.size - 1 - j][R.y + i];
            }
        }

        X = nX;
        Y = nY;

        for (auto& p : people) {
            int x = p.second.x;
            int y = p.second.y;

            if (R.x <= x && x < R.x + R.size && R.y <= y && y < R.y + R.size) {
                int nx = R.x - R.y + y;
                int ny = R.x + R.y + R.size - x -1;
                people[p.first] = { nx,ny};
            }
        }

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                Map[i][j] = temp[i][j];
            }
        }
    }
    cout << answer << '\n';
    cout << X << " " << Y << '\n';
    return 0;
}