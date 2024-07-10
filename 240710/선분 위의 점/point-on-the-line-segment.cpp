#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int n,m;
    long long arr[100001];

    cin>>n>>m;
    set<pair<long long, int>> sets;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    for(int i=0; i<m; i++){
        int ans;
        int x,y;
        cin>>x>>y;

        int count = upper_bound(arr, arr+n, y) - lower_bound(arr, arr+n, x);
        cout<<count<<'\n';
    }
    return 0;
}