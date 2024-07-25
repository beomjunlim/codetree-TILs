#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin>>n;

    int arr[10001];
    int sum = 0;

    for(int i=0; i<n; i++){
        cin>>arr[i];
        sum += arr[i];
    }
    
    sum = sum/n;
    int ans = 0;

    for(int i=0; i<n; i++){
        ans += abs(sum - arr[i]);
    }

    cout<<ans/2;
    return 0;
}