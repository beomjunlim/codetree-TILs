#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int n,h,t;
    cin>>n>>h>>t;

    int arr[101];
    int ans = 987654321;

    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    for(int i=0; i<=n-t; i++){
        int sum = 0;
        for(int j=i; j<i+t; j++){
            sum += abs(h-arr[j]);
        }
        ans = min(ans, sum);
    }
    cout<<ans;
    return 0;
}