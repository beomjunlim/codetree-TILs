#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n,m;
    long long arr[100001];

    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    sort(arr, arr+n);
    for(int i=0; i<m; i++){
        int ans;
        int x,y;
        cin>>x>>y;

        int a = upper_bound(arr, arr+n, y)-arr;
        int b =   lower_bound(arr, arr+n, x)-arr;
        cout<<a-b<<'\n';
    }
    return 0;
}