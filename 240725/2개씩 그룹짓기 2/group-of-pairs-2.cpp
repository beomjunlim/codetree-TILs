#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin>>n;

    int arr[200001];

    for(int i=0; i<2*n; i++)
        cin>>arr[i];
    
    sort(arr, arr+2*n);

    int sum[100001];
    int ans = (int)1e9;

    for(int i=0; i<n; i++)
        sum[i] = arr[i];
    
    for(int i=n; i<2*n; i++){
        ans = min(ans, arr[i] - sum[i-n]);
    }

    cout<<ans;
    return 0;
}