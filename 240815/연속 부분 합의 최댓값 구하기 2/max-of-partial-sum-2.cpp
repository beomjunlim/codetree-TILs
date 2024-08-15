#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int arr[100001];
int sum[100001];

int main() {
    int n;
    cin>>n;

    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }

    sum[0] = 0;

    for(int i=1; i<=n; i++){
        sum[i] = max(sum[i-1] + arr[i], arr[i]);
    }


    int ans = INT_MIN;

    for(int i=1; i<=n; i++){
        ans = max(ans, sum[i]);
    }

    cout<<ans;
    return 0;
}