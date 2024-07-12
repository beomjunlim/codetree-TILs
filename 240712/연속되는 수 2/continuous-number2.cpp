#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin>>n;

    int arr[1001];

    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    int ans = 1;

    int num = arr[0];
    int cnt = 1;
    for(int i=1; i<n; i++){
        if(num==arr[i])
            cnt++;
        else{
            ans = max(ans, cnt);
            num = arr[i];
            cnt = 1;
        }
    }
    
    ans = max(ans, cnt);
    cout<<ans;
    return 0;
}