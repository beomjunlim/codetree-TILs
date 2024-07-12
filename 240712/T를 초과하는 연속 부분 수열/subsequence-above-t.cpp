#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n,t;
    cin>>n>>t;

    int arr[1001];

    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    int ans = 0;
    int cnt = 0;

    for(int i=0; i<n; i++){
        if(arr[i]>t){
            cnt++;
        }
        else{
            ans= max(ans, cnt);
            cnt = 0;
        }
    }
    ans = max(ans, cnt);
    cout<<ans;
    return 0;
}