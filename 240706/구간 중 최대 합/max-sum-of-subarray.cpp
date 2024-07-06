#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n,k;
    int arr[101];
    cin>>n>>k;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int ans = 0;

    for(int i=0; i<n-k; i++){
        int sum = 0;
        for(int j=i; j<i+k; j++){
            sum += arr[j];
        }
        ans = max(ans, sum);
    }

    cout<<ans;
    return 0;
}