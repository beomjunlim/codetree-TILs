#include <iostream>
using namespace std;

int main() {
    int n,k;
    cin>>n>>k;

    int arr[1001] = {0};
    int sum[1001] = {0};
    for(int i=1; i<=n; i++)
        cin>>arr[i];
    
    sum[1] = arr[1];

    for(int i=2; i<=n; i++)
        sum[i] = sum[i-1] + arr[i];
    
    int ans = 0;
    
    for(int i=1; i<=n; i++){
        for(int j=i; j<=n; j++){
            int cnt = sum[j] - sum[j-i];
            if(cnt==k){
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}