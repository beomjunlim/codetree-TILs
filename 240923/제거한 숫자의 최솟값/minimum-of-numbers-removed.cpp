#include <iostream>
#include <algorithm>
using namespace std;

long long arr[10001];

int main() {
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    sort(arr, arr+n);
    
    int start = 0;
    int end = n-1;
    long long ans = 0;

    if(n%2!=0){
        ans = arr[end];
        end = n-2;
    }

    while(start<end){
        long long num = arr[start] + arr[end];
        ans = max(ans, num);
        start++;
        end--;
    }

    cout<<ans;
    return 0;
}