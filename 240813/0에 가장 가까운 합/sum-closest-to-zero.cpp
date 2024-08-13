#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int arr[100001];

int main() {
    int n;
    cin>>n;

    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }    

    sort(arr+1, arr+n+1);

    int ans = 9*1e9;
    int j=n;
    for(int i=1; i<=n; i++){
        if(i<j){
            ans = min(ans, abs(arr[i] + arr[j]));
        }
        while(i<j&&arr[i] + arr[j]>0){
            ans = min(ans, abs(arr[i] + arr[j]));
            j--;
        }
    }

    cout<<ans;

    return 0;
}