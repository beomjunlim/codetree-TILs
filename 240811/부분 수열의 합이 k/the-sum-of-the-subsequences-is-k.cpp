#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001];
int sum[1001];

int main() {
    int n,k;
    cin>>n>>k;

    for(int i=1; i<=n; i++){
        cin>>arr[i];
        sum[i] = sum[i-1] + arr[i];
    }

    int ans = 0;

    for(int i=1; i<=n; i++){
        for(int j=i; j<=n; j++){
            if(sum[j] - sum[j-i]==k)
                ans++;
        }
    }

    cout<<ans;
    return 0;
}