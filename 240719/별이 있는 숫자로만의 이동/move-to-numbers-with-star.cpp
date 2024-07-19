#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n, m;
int arr[401][401];
long long sum[401][401] = {0};

bool InRange(int x, int y){
    return 0 < x && x <= n && 0 < y && y <= n;
}

void ComputePrefixSum() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            sum[i][j] = arr[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
        }
    }
}

long long GetSum(int x1, int y1, int x2, int y2) {
    if (x1 > x2 || y1 > y2) return 0;
    return sum[x2][y2] - sum[x1-1][y2] - sum[x2][y1-1] + sum[x1-1][y1-1];
}

long long GetArea(int x, int y) {
    long long sum = 0;
    for (int dx = -m; dx <= m; dx++) {
        int x1 = x + dx;
        if (!InRange(x1, y)) continue;
        int dy = m - abs(dx);
        int y1 = max(1, y - dy);
        int y2 = min(n, y + dy);
        sum += GetSum(x1, y1, x1, y2);
    }
    return sum;
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    ComputePrefixSum();

    long long ans = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ans = max(ans, GetArea(i, j));
        }
    }

    cout << ans;
    return 0;
}