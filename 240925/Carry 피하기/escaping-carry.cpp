#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n;
int answer = 0;
int arr[21];

// carry 발생 여부를 체크하는 함수
bool checkCarry(const vector<int>& selected) {
    int carry[10] = {0}; // 각 자리별로 합을 저장하는 배열

    // 선택된 숫자들에 대해 각 자리의 합을 구함
    for (int num : selected) {
        for (int i = 0; num > 0; i++, num /= 10) {
            carry[i] += num % 10; // 각 자릿수를 더함
        }
    }

    // carry 발생 여부 체크
    for (int i = 0; i < 10; i++) {
        if (carry[i] >= 10) return false; // carry 발생
    }

    return true; // carry가 발생하지 않음
}

// 부분집합을 비트마스크로 확인
void solve() {
    for (int mask = 1; mask < (1 << n); ++mask) { // 모든 부분집합을 비트마스크로 탐색
        vector<int> selected;

        // 현재 비트마스크에 해당하는 숫자들을 선택
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                selected.push_back(arr[i]);
            }
        }

        // 선택된 숫자들에 대해 carry 발생 여부 체크
        if (checkCarry(selected)) {
            answer = max(answer, (int)selected.size());
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    solve(); // 최적화된 부분집합 탐색

    cout << answer << endl;
    return 0;
}