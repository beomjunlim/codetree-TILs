#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 가장 긴 증가하는 부분 수열의 길이를 구하는 함수
int LIS(vector<int>& seq) {
    vector<int> lis;
    for (int i = 0; i < seq.size(); i++) {
        auto it = lower_bound(lis.begin(), lis.end(), seq[i]);
        if (it == lis.end()) {
            lis.push_back(seq[i]);
        } else {
            *it = seq[i];
        }
    }
    return lis.size();
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> lines(n);
    
    for (int i = 0; i < n; i++) {
        cin >> lines[i].first >> lines[i].second;
    }

    // 두 번째 점 번호를 기준으로 오름차순 정렬
    sort(lines.begin(), lines.end());

    // 두 번째 점 번호만 따로 추출하여 LIS를 계산
    vector<int> seq;
    for (int i = 0; i < n; i++) {
        seq.push_back(lines[i].second);
    }

    int lis_length = LIS(seq);
    
    // 제거해야 하는 최소 선의 개수는 전체 선의 개수에서 LIS의 길이를 뺀 값
    cout << n - lis_length << endl;

    return 0;
}