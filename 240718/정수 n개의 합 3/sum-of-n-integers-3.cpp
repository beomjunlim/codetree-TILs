#include <iostream>
using namespace std;

int main() {
    int n,k;
    cin>>n>>k;

    int arr[501][501] = {0};
    int sum[501][501] = {0};

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>arr[i][j];
        }
    }

    sum[1][1] = arr[1][1];

    for(int i=2; i<=n; i++){
        sum[1][i] = sum[1][i-1] + arr[1][i];
        sum[i][1] = sum[i-1][1] + arr[i][1];
    }

    for(int i=2; i<=n; i++){
        for(int j=2; j<=n; j++){
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + arr[i][j];
        }
    }



    int ans = 0;
    for(int i=k; i<=n; i++){
        for(int j=k; j<=n; j++){
            int cnt = sum[i][j] - sum[i-k][j] - sum[i][j-k] + sum[i-k][j-k];
            ans = max(ans,cnt);
        }
    }

    cout<<ans;
    
    return 0;
}