#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n,m;
int arr[401][401];
int sum[401][401];

int main() {
    cin>>n>>m;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>arr[i][j];
        }
    }    

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            sum[i][j] = sum[i][j-1] + arr[i][j];
        }
    }

    int ans = 0;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int sum_all = 0;
            for(int r=i-m; r<=i+m; r++){
                int c = m - abs(i-r);
                if(1<=r&r<=n)
                    sum_all += (sum[r][min(j+c,n)] - sum[r][max(j-c-1,0)]);
            }
            ans = max(ans, sum_all);
        }
    }

    cout<<ans;
   return 0;
}