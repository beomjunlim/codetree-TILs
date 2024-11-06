#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long n;
    cin>>n;

    long long left = 1;
    long long right = 2000000000;
    long long sum = 0;

    while(left<=right){
        long long mid = (left + right) / 2;

        if(mid*(mid+1)/2<=n){
            left = mid + 1;
            sum = max(sum,mid);
        }
        else
            right = mid - 1;
    }

    cout<<sum;
    return 0;
}