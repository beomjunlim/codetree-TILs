#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n,k,b;
    cin>>n>>k>>b;

    bool arr[100001] = {false};
    int sum[100001] = {0};
    for(int i=0; i<b; i++){
        int a;
        cin>>a;
        arr[a] = true;
    }

    for(int i=1; i<=n; i++){
        if(arr[i])
            sum[i] = sum[i-1] + 1;
        else
            sum[i] = sum[i-1];
    }

    int ans = n;
    for(int i=k; i<=n; i++){
        ans = min(ans, sum[i] - sum[i-k]);
    }

    cout<<ans;
    return 0;
}