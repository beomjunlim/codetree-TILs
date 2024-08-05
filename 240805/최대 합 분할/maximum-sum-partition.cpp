#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

#define MAX_N 100
#define MAX_M 100000
#define OFFSET 100000 // 음수가 될 수 있으므로

int n;
int sum = 0;
int arr[MAX_N + 1];
int dp[MAX_N + 1][MAX_M + 1 + OFFSET]; // i번째 수까지 고려했을 경우 A, B 그룹의 차이가 j

void Update(int i, int j, int prev_i, int prev_j, int val){
    if(prev_j<-sum||prev_j>sum||dp[prev_i][prev_j + OFFSET] == INT_MIN)
        return;
    
    dp[i][j + OFFSET] = max(dp[i][j + OFFSET], dp[prev_i][prev_j + OFFSET] + val);
}

int main() {
    cin>>n;

    for(int i=1; i<=n; i++){
        cin>>arr[i];
        sum += arr[i];
    }

    for(int i=0; i<=n; i++){
        for(int j=-sum; j<=sum; j++)
            dp[i][j + OFFSET] = INT_MIN;
    }

    dp[0][0 + OFFSET] = 0;

    for(int i=1; i<=n; i++){
        for(int j=-sum; j<=sum; j++){
            Update(i, j, i-1, j - arr[i], arr[i]); // A에 i 번째 원소 추가하여 A - B  가 j 가 되는 경우
            Update(i, j, i-1, j + arr[i], 0); // B에 i 번째 원소 추가하여 A - B  가 j 가 되는 경우
            Update(i, j, i-1, j, 0); // C에 넣어서 j 가 되는 경우
        }
    }
    cout<<dp[n][0 + OFFSET];
    return 0;
}