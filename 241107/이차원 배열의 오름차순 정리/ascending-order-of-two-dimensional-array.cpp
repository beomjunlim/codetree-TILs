#include <iostream>
using namespace std;

int main() {
    long long n,k;
    cin>>n>>k;

    long long left = 1;
    long long right = n*n;
    long long ans = n*n;

    while(left<=right){
        long long mid = (left+right)/2;

        long long cnt = 0;
        for(int i=1; i<=n; i++){
            cnt += min(n, mid/i);
        }

        if(cnt>=k){
            right = mid - 1;
            ans = min(ans, mid);
        }
        else
            left = mid + 1;
    }

    cout<<ans;
    return 0;
}