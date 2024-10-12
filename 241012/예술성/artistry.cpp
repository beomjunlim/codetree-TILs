#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <unordered_map>
#include <cstring>
#include <map>
using namespace std;

int n;
int idx;
int totalScore = 0;
int arr[30][30];
int Group[30][30];
bool visited[31][31];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int wall[1001][1001];
map<int, int> Block;
pair<int, int> IdxNum[1001];
bool visitedBlock[1001];

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

void makeGroup(int a, int b, int num, int idx) {
    queue<pair<int, int>> q;
    q.push({ a,b });
    visited[a][b] = true;
    Group[a][b] = idx;
    int cnt = 1;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (InRange(nx, ny) && !visited[nx][ny] && arr[nx][ny] == num) {
                Group[nx][ny] = idx;
                visited[nx][ny] = true;
                q.push({ nx,ny });
                cnt++;
            }
        }
    }
    Block[idx] = cnt;
    IdxNum[idx] = { a,b };
}

void makeWall(int a, int b, int idx) {
    queue<pair<int, int>> q;
    q.push({ a,b });
    visited[a][b] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (InRange(nx, ny) && Group[nx][ny] != idx)
                wall[idx][Group[nx][ny]]++;

            if (InRange(nx, ny) && !visited[nx][ny] && Group[nx][ny] == idx) {
                visited[nx][ny] = true;
                q.push({ nx,ny });
            }
        }
    }
}

void countScore() {
    for(int i=0; i<idx; i++){
        Block[i] = 0;
        IdxNum[i] = {0,0};
    }

    for(int i=1; i<idx; i++){
        for(int j=1; j<idx; j++){
            wall[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            Group[i][j] = 0;
        }
    }

    idx = 1;
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                makeGroup(i, j, arr[i][j], idx);
                idx++;
            }
        }
    }

    memset(visited, false, sizeof(visited));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                makeWall(i, j, Group[i][j]);
            }
        }
    }

    int answer = 0;
    for (int i = 1; i < idx; i++) {
        int aCnt = Block[i];
        int aNum = arr[IdxNum[i].first][IdxNum[i].second];
       // cout<<IdxNum[i].first<<" "<<IdxNum[i].second<<'\n';
        for (int j = i + 1; j < idx; j++) {
            int bCnt = Block[j];
            int bNum = arr[IdxNum[j].first][IdxNum[j].second];
            int w = wall[i][j];
            if(w==0)
                continue;
        //   cout<<"ac "<<aCnt<<" bc "<<bCnt<<" an "<<aNum<<" bn "<<bNum<<" w "<<w<<" i "<<i<<" j "<<j<<'\n';
            int tmp = (aCnt + bCnt);
            tmp *=aNum;
            tmp *=bNum;
            tmp *=w;

            answer += tmp;
        }
    }
    totalScore += answer;
}

void rotate() {
    int temp[31][31];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[i][j] = arr[i][j];
        }
    }

    int size = n / 2;

    for (int i = 0; i < n; i++) {
        temp[i][size] = arr[size][n-1-i];
        temp[size][i] = arr[i][size];
    }

    for (int i = 0; i <size; i++) {
        for (int j = 0; j < size; j++) {
            temp[i][j] = arr[size - j - 1][i];
            temp[i][size + 1 + j] = arr[size-j-1][size + 1 + i];
            temp[size + 1 + i][j] = arr[2*size-j][i];
            temp[size + 1 + i][size + 1 + j] = arr[2 * size - j][size + 1 + i];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = temp[i][j];
        }
    }
    
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    countScore();
    for (int i = 0; i < 3; i++) {
        rotate();
        countScore();
    }

    
    cout << totalScore;
   
    return 0;
}