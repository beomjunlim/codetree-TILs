#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];
int sum[100001];
int main() {
    int n,k;
    cin>>n>>k;

    for(int i=1; i<=n; i++){
        cin>>arr[i];
        sum[i] = sum[i-1] + arr[i];
    }

    int ans = 0;
    for(int i=k; i<=n; i++){
        ans = max(ans, sum[i] - sum[i-k]);
    }

    cout<<ans;
    return 0;
}