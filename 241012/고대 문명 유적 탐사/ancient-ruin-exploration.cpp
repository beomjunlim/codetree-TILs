#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <unordered_map>
#include <cstring>
#include <map>
using namespace std;

int K, M;
int arr[6][6];
int temp[6][6];
bool visited[6][6];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int peice[301];
int Pidx = 0;
vector<pair<int, int>> canGet;

bool InRange(int x, int y) {
    return 0 <= x && x < 5 && 0 <= y && y < 5;
}

bool getGold(int a, int b, int &cnt) {
    int num = temp[a][b];
    queue<pair<int, int>> q;
    q.push({ a,b });
    visited[a][b] = true;
    cnt = 1;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (InRange(nx, ny) && !visited[nx][ny] && temp[nx][ny] == num) {
                cnt++;
                visited[nx][ny] = true;
                q.push({ nx,ny });
            }
        }
    }

    if (cnt >= 3) {
        return true;
    }
        
    return false;
}

void Rotated(int angle, int r, int c) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            temp[i][j] = arr[i][j];
        }
    }
    r = r -1;
    c = c -1;
    if (angle == 1) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                temp[r + i][c + j] = arr[r + 2 - j][c + i];
            }
        }
    }
    else if (angle == 2) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                temp[r + i][c + j] = arr[r + 2 - i][c + 2 - j];
            }
        }
    }
    else if (angle == 3) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                temp[r + i][c + j] = arr[r + j][c + 2 - i];
            }
        }
    }
}

int getNum() {
    int total = 0;
    memset(visited, false, sizeof(visited));
    canGet = vector<pair<int, int>>();

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (!visited[i][j]) {
                int num = 0;
                if (getGold(i, j, num)) {
                    canGet.push_back({ i,j });
                    total += num;
                }
            }
        }
    }
    return total;
}

void fillMap() {   
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < canGet.size(); i++) {
        int x = canGet[i].first;
        int y = canGet[i].second;
        int count =0;
        getGold(x, y, count);
    }


    for (int i = 0; i < 5; i++) {
        for (int j = 4; j >= 0; j--) {
            if (visited[j][i]) {
                temp[j][i] = peice[Pidx];
                Pidx++;
                if (Pidx == M)
                    Pidx = 0;
            }
        }
    }


}

int main() {
    cin >> K >> M;

    for(int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < M; i++) {
        cin >> peice[i];
    }

    while (K--) {

        int cnt = 0;
        int angle, x, y;
        for (int an = 1; an <= 3; an++) {
            for (int j = 1; j <= 3; j++) {
                for (int i = 1; i <= 3; i++) {
                    Rotated(an, i, j);
                    int num = getNum();
                    if (cnt < num) {
                        cnt = num;
                        angle = an;
                        x = i;
                        y = j;
                    }
                }
            }
        }

        if (cnt == 0)
            break;

        Rotated(angle, x, y);


        int gold = getNum();

        fillMap();
        
        while (1) {
            int num = getNum();

            if (num == 0)
                break;
            gold += num;
            fillMap();
        }
        
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                arr[i][j] = temp[i][j];
            }
        }
        cout << gold << " ";
    }

    return 0;
}