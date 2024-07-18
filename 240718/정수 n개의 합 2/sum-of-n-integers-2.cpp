#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n,k;
    cin>>n>>k;

    int arr[100001];
    int sum[100001];
    for(int i=0; i<n; i++){
        cin>>arr[i];
        if(i==0)
            sum[i] = arr[i];
        else
            sum[i] = sum[i-1] + arr[i];
    }

    int ans = sum[k-1];

    for(int i=k; i<n; i++){
        ans = max(ans, sum[i] - sum[i-k]);
    }

    cout<<ans;
    return 0;
}