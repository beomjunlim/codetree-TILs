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
    int x, y;
};

struct Rotate {
    int x, y, size;
};

int N, M, K;
int X, Y;
int Map[11][11];
map<int, People> people;
bool escape[11];

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

bool InRange(int x, int y) {
    return 0 < x && x <= N && 0 < y && y <= N;
}

bool CanRotate(int x, int y, int size) {
    if (x <= X && X < x + size && y <= Y && Y < y + size) {
        for (auto person : people) {
            int px = person.second.x;
            int py = person.second.y;

            if (x <= px && px < x + size && y <= py && py < y + size)
                return true;
        }
    }
    return false;
}

Rotate rotate() {
    for (int size = 2; size <= N; size++) {
        for (int i = 1; i <= N - size + 1; i++) {
            for (int j = 1; j <= N - size + 1; j++) {
                if (CanRotate(i, j, size)) {
                    return {i,j,size};
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

    int answer = 0;
    cin >> X >> Y;

    while (K > 0) {
        for (auto& person : people) {
            int x = person.second.x;
            int y = person.second.y;

            int dist = abs(X - x) + abs(Y - y);
            int nextX = x, nextY = y;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                int next = abs(X - nx) + abs(Y - ny);

                if (InRange(nx, ny) && Map[nx][ny] == 0 && next < dist) {
                    dist = next;
                    nextX = nx;
                    nextY = ny;
                }
            }

           // cout<<K<<" move : "<<x<<" "<<y<<" "<<nextX<<" "<<nextY<<'\n';
            if (nextX == x && nextY == y)
                continue;

            answer++;

            if (nextX == X && nextY == Y) {
                escape[person.first] = true;
                continue;
            }

            people[person.first] = { nextX, nextY };
        }

        for (int i = 1; i <= M; i++) {
            if (escape[i])
                people.erase(i);
        }

        if (people.size() == 0)
            break;

        Rotate R = rotate();
        int x = R.x;
        int y = R.y;
        int size = R.size;
      //  cout<<size<<" "<<x<<" "<<y<<" hh"<<'\n';

        int temp[11][11] = {0};

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                temp[i][j] = Map[i][j];
            }
        }
        
        int nX = X;
        int nY = Y;

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (x + i == X && y + j == Y) {
                    nX = x + j;
                    nY = y + size - 1 - i;
                }
                if (Map[x + i][y + j] > 0)
                    Map[x + i][y + j]--;
                temp[x + j][y + size -1 -i] = Map[x + i][y + j];
            }
        }

        X = nX;
        Y = nY;

        for (auto& person : people) {
            int nx = person.second.x;
            int ny = person.second.y;

            if (x <= nx && nx < x + size && y <= ny && ny < y + size) {
                int ax = x + ny - y;
                int ay = y + x + size - nx - 1;
                people[person.first] = { ax,ay };
            }
        }

        for (int i = 1; i <=N; i++) {
            for (int j = 1; j <=N; j++) {
                Map[i][j] = temp[i][j];
            }
        }
        K--;
    }

    cout << answer << '\n';
    cout << X << " " << Y << '\n';
    return 0;
}