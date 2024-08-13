#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];

int main() {
    int n,s;
    cin>>n>>s;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int ans = n+1;
    int sum = 0;
    int j = 0;

    for(int i=0; i<n; i++){
        while(j<n&&sum<s){
            sum += arr[j];
            j++;
        }

        if(sum>=s)
            ans = min(ans, j - i);
        sum -= arr[i];
    }

    if(ans==n+1)
        ans = -1;
    
    cout<<ans;
    return 0;
}