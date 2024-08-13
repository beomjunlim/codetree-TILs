#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];

int main() {
    int n,k;
    cin>>n>>k;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    sort(arr, arr+n);
    int ans = 0;
    int start = 0;
    int end = start + 1;
    while(start<end){
        int sum = arr[start] + arr[end];

        if(sum<=k){
            ans++;
            end++;
        }
        else if(sum>k){
            start++;
        }
    }

    cout<<ans;
    return 0;
}