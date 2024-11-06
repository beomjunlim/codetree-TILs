#include <iostream>
using namespace std;


long long find(long long n){
    return n - n/3 -n/5 + n/15;
}

int main() {
    long long n;
    cin>>n;

    long long left = 1;
    long long right = 2000000000;
    long long ans = 2000000000;

    while(left<=right){
        long long mid = (left + right) / 2;

        long long num = find(mid);

        if(num>=n){
            right = mid - 1;
            ans = min(ans, mid);
        }
        else
            left = mid + 1;
    }

    cout<<ans;
    return 0;
}