#include <iostream>
#include <algorithm>
using namespace std;

long long arr[100001];
long long cost[100001];
long long min_arr[100001];

int main() {
    int n;
    cin>>n;

    long long sum = 0;
    for(int i=1; i<n; i++){
        cin>>cost[i];
        sum += cost[i];
    }

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    min_arr[0] = arr[0];

    for(int i=1; i<n; i++){
        min_arr[i] = min(min_arr[i-1], arr[i]);
    }

    long long ans = 0;

    for(int i=1; i<n; i++){
        ans += cost[i]*min_arr[i-1];
    }

    cout<<ans;
    return 0;
}