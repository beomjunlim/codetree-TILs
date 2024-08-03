#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<vector<int>> grid;
vector<vector<bool>> visited;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool isInside(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

vector<pair<int, int>> bfs() {
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;
    vector<pair<int, int>> melting_positions;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (isInside(nx, ny) && !visited[nx][ny]) {
                if (grid[nx][ny] == 0) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                } else if (grid[nx][ny] == 1) {
                    visited[nx][ny] = true;
                    melting_positions.push_back({nx, ny});
                }
            }
        }
    }

    return melting_positions;
}

int main() {
    cin >> N >> M;
    grid.resize(N, vector<int>(M));
    visited.resize(N, vector<bool>(M, false));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> grid[i][j];
        }
    }

    int time = 0;
    int last_melting_size = 0;

    while (true) {
        visited.assign(N, vector<bool>(M, false));
        vector<pair<int, int>> melting_positions = bfs();
        if (melting_positions.empty()) {
            break;
        }
        last_melting_size = melting_positions.size();
        for (auto pos : melting_positions) {
            grid[pos.first][pos.second] = 0;
        }
        time++;
    }

    cout << time << " " << last_melting_size << endl;
    return 0;
}