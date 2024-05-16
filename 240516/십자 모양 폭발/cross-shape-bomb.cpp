#include <iostream>
using namespace std;

int n, r, c;
int arr[201][201];
int next_arr[201][201]; // next_arr 추가

void down(int y) {
    for (int i = n - 1; i > 0; i--) {
        if (arr[i][y] == 0) {
            for (int k = i; k > 0; k--) {
                arr[k][y] = arr[k - 1][y];
            }
            arr[0][y] = 0;
        }
    }
}

void row() {
    int num = arr[r][c];
    int start = 0;
    int end = n - 1;

    if (r - num + 1 >= 0)
        start = r - num + 1;

    if (r + num - 1 < n)
        end = r + num - 1;

    for (int i = start - 1; i >= 0; i--) {
        arr[end][c] = arr[i][c];
        end--;
    }

    for (int i = r - num + 1; i <= r + num - 1; i++) {
        arr[i][c] = 0;
    }
}

void bomb() {
    int num = arr[r][c];
    int start = 0;
    int end = n - 1;

    if (c - num + 1 >= 0)
        start = c - num + 1;

    if (c + num - 1 < n)
        end = c + num - 1;

    for (int i = start; i <= end; i++) {
        if (i == c) {
            row();
        } else {
            down(i);
        }
    }

    // 폭탄이 터진 이후의 결과를 next_arr에 저장합니다.
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            next_arr[i][j] = 0;

    for (int j = 0; j < n; j++) {
        int next_row = n - 1;
        for (int i = n - 1; i >= 0; i--) {
            if (arr[i][j])
                next_arr[next_row--][j] = arr[i][j];
        }
    }

    // next_arr 값을 arr로 옮깁니다.
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            arr[i][j] = next_arr[i][j];
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    cin >> r >> c;
    r--; // 1-based index를 0-based로 변경
    c--;

    bomb();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}