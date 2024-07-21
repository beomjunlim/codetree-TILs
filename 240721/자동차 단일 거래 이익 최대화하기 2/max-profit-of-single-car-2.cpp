#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;

    long long arr[100001];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    long long ans = 0;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            ans = max(ans, arr[j] - arr[i]);
        }
    }
    cout<<ans;
    return 0;
}