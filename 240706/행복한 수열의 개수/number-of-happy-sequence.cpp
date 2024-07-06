#include <iostream>
using namespace std;

int n, m;
int arr[101][101];

int check(int low) {
    bool sw_a = false;
    for (int i = 0; i <= n - m; i++) {
        int num = arr[low][i];
        int idx = 0;
        bool sw = true;
        for (int j = i + 1; j < i + m; j++) {
            if (num != arr[low][j]) {
                idx = j;
                sw = false;
                break; // 바로 빠져나감
            }
        }
        if (!sw)
            i = idx - 1; // i를 idx - 1로 설정하여 다시 시도
        else {
            sw_a = true;
            break; // 일치하는 경우가 있으면 바로 종료
        }
    }

    bool sw_b = false;
    for (int i = 0; i <= n - m; i++) {
        int num = arr[i][low];
        int idx = 0;
        bool sw = true;
        for (int j = i + 1; j < i + m; j++) {
            if (num != arr[j][low]) {
                idx = j;
                sw = false;
                break; // 바로 빠져나감
            }
        }
        if (!sw)
            i = idx - 1; // i를 idx - 1로 설정하여 다시 시도
        else {
            sw_b = true;
            break; // 일치하는 경우가 있으면 바로 종료
        }
    }

    if (sw_a && sw_b)
        return 2;
    else if (sw_a || sw_b)
        return 1;
    else
        return 0;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int num = check(i);
        sum += num;
    }
    cout << sum;
    return 0;
}