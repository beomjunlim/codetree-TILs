#include <iostream>
#include <algorithm>
using namespace std;

int arr[10001];

int main() {
    int n,m;
    cin>>n>>m;

    int maxN = 0;

    for(int i=0; i<n; i++){
        cin>>arr[i];
        maxN = max(maxN, arr[i]);
    }

    sort(arr, arr + n);
    int ans = 0;
    int left = 1;
    int right = maxN;
    
    while(left<=right){
        int mid = (left+right)/2;
        int cnt = 0;

        for(int i=0; i<n; i++){
            cnt += arr[i]/mid;
        }

        if(cnt>=m){
            left = mid + 1;
            ans = max(ans,mid);
        }
        else
            right = mid - 1;
        
    }

    cout<<ans;
    return 0;
}