#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int ans = 0;
int arr[50001];
int sum[50001];
int dp_left[50001];
int dp_right[50001];

int main() {
    cin>>n;
    
    sum[0] = 0;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
        sum[i] = arr[i] + sum[i-1];
    }

    cin>>m;

    int max_left = 0;
    for(int i=m; i<=n; i++){
        int temp = sum[i] - sum[i-m];
        max_left = max(max_left, temp);
        dp_left[i] = max_left;
    }

    int max_right = 0;
    for(int i= n-m+1; i>=1; i--){
        int temp = sum[i+m-1] - sum[i-1];
        max_right = max(max_right, temp);
        dp_right[i] = max_right;
    }

    for(int i=m+1; i<=n-m; i++){
        int left_max = dp_left[i-1];
        int right_max = dp_right[i+m];
        int mid = sum[i+m-1] - sum[i-1];
        ans = max(ans, left_max + mid + right_max);
    }

    cout<<ans;
    return 0;
}