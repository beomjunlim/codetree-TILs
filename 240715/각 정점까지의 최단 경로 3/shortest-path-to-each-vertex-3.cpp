#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[101][101] = {0};
int dist[101];
bool visited[101];

void dijkstra(int start) {
    fill(dist, dist + 101, 987654321); // dist 배열 초기화
    dist[start] = 0;

    for (int i = 1; i <= n; i++) {
        int x = 987654321;
        int idx = -1;

        for (int j = 1; j <= n; j++) {
            if (!visited[j] && dist[j] < x) {
                x = dist[j];
                idx = j;
            }
        }

        if (idx == -1) break;

        visited[idx] = true;

        for (int j = 1; j <= n; j++) {
            if (!visited[j] && arr[idx][j] != 0) {
                dist[j] = min(dist[j], dist[idx] + arr[idx][j]);
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x, y, dis;
        cin >> x >> y >> dis;
        arr[x][y] = dis;
    }

    dijkstra(1);

    for (int i = 2; i <= n; i++) {
        if (dist[i] == 987654321)
            cout << -1 << '\n';
        else
            cout << dist[i] << '\n';
    }

    return 0;
}