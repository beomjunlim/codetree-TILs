// #include <iostream>
// #include <climits>
// #include <algorithm>
// using namespace std;

// int n;
// int R[205];
// int B[205];
// int dp[205][105];

// int main() {
//     cin>>n;

//     for(int i=1; i<=2*n; i++){
//         cin>>R[i]>>B[i];
//     }
    
//     dp[0][0];
    
//     for(int i=1; i<=n; i++)
//         dp[i][0] = dp[i-1][0] + B[i];
    
//     for(int i=1; i<=n; i++)
//         dp[n+i][0] = dp[n+i-1][0] + R[n+i];

//     for(int i=1; i<=2*n; i++){
//         for(int j=1; j<=n; j++){
//             if(i<j)
//                 continue;
            
//             if(i!=j)
//                 dp[i][j] = max(dp[i][j], dp[i-1][j] + B[i]);
            
//             dp[i][j] = max(dp[i][j], dp[i-1][j-1], R[i]);
//         }
//     }

//     cout<<dp[2*n][n];
//     return 0;
// }

#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int n;
int R[205];
int B[205];
int dp[205][105];

int main() {
    cin >> n;

    for(int i = 1; i <= 2 * n; i++) {
        cin >> R[i] >> B[i];
    }

    // dp 배열 초기화
    for (int i = 0; i <= 2 * n; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = INT_MIN; // 최대 값을 찾기 위해 최소 값으로 초기화
        }
    }

    dp[0][0] = 0; // 시작 상태 초기화

    // dp 배열 채우기
    for (int i = 1; i <= 2 * n; i++) {
        for (int j = 0; j <= min(i, n); j++) {
            if (j > 0) {
                // i 번째를 Red로 선택
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + R[i]);
            }
            // i 번째를 Blue로 선택
            dp[i][j] = max(dp[i][j], dp[i-1][j] + B[i]);
        }
    }

    cout << dp[2 * n][n] << endl;
    return 0;
}