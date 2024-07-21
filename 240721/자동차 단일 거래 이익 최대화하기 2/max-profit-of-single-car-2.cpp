#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;

    long long arr[100001];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    long long ans = 0;
    long long price = arr[0];
    for(int i=1; i<n; i++){
        ans = max(ans, arr[i] - price);
        if(price > arr[i])
            price = arr[i];
    }
    cout<<ans;
    return 0;
}