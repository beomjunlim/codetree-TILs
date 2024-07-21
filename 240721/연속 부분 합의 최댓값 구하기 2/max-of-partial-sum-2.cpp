#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    int arr[100001];
    int sum[100001];
    cin>>n;

    for(int i=1; i<=n; i++){
        cin>>arr[i];
        sum[i] = sum[i-1] + arr[i];
    }

    int ans = -10000;
    for(int i=1; i<=n; i++){
        sum[i] = arr[i] + sum[i-1];
        if(sum[i-1]<0)
            sum[i] = arr[i];
        ans = max(ans, sum[i]);
    }

    cout<<ans;
    return 0;
}