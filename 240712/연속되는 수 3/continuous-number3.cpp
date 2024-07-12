#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin>>n;

    int arr[1001];

    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    bool sw;
    if(arr[0]>0)
        sw = true;
    else
        sw = false;
    int ans = 0;
    int cnt = 1;

    for(int i=1; i<n; i++){
        if((sw&&arr[i]<0)||(!sw&&arr[i]>0)){
            sw = !sw;
            ans = max(ans, cnt);
            cnt = 1;
        }
        else
            cnt++;
    }
    ans = max(ans, cnt);
    cout<<ans;
    return 0;
}