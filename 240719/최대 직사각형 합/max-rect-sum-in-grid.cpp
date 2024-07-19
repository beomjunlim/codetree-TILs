#include <iostream>
using namespace std;

int main() {
    int n;
    int arr[301][301] = {0};
    int sum[301][301] = {0};
    cin>>n;

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
            sum[i][j] = arr[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
        }
    }

    int ans = -(int)1e9;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            for(int k=i; k<=n; k++){
                for(int l=j; l<=n; l++){
                    int cnt = sum[k][l] - sum[k-i][l] - sum[k][l-j] + sum[k-i][l-j];
                    ans = max(ans, cnt);
                }
            }
        }
    }
    cout<<ans;
    return 0;
}