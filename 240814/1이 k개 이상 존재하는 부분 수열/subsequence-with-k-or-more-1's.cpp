#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000001];
int sum[1000001];

int main() {
    int n,k;
    cin>>n>>k;

    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }

    for(int i=1; i<=n; i++){
        int num = 0;
        if(arr[i]==1)
            num = 1;
        sum[i] = sum[i-1] + num;
    }

    int ans = n+1;
    int j=1;
    for(int i=1; i<=n; i++){
        while(j<=n&&sum[j]-sum[i-1]<k){
            j++;
        }

        if(j<=n)
            ans = min(ans, j-i+1);
    }

    if(ans==n+1)
        ans = -1;
        
    cout<<ans;
    return 0;
}