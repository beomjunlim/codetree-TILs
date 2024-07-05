#include <iostream>
#include <algorithm>
using namespace std;

int n;
int ans =987654321;
int arr[1004];
int main() {
    cin>>n;

    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }

    for(int i=1; i<=n; i++){
        int sum = 0;
        int idx = 0;
        int start = i;
        while(idx<n){
            start++;
            if(start==n+1)
                start = 1;
            sum += idx*arr[start];
            idx++;
        }
        ans = min(ans, sum);
    }

    cout<<ans;
    return 0;
}