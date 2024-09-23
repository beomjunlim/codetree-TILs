#include <iostream>
#include <algorithm>
using namespace std;

int arr[10001];

int main() {
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    sort(arr, arr+n);

    int start = 0;
    int end = n-1;
    int ans = 0;

    while(start<=end){
        int num = arr[start] + arr[end];
        ans = max(ans, num);
        start++;
        end--;
    }

    cout<<ans;
    return 0;
}