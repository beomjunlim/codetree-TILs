#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n,m;
    long long arr[100001];

    cin>>n>>m;

    for(int i=0; i<n; i++)
        cin>>arr[i];

    for(int i=0; i<m; i++){
        int x;
        cin>>x;

        int min_idx = lower_bound(arr, arr+n, x) - arr;
        int max_idx = upper_bound(arr, arr+n, x) - arr;
        int cnt = max_idx - min_idx;
        cout<<cnt<<'\n';
    }
    return 0;
}