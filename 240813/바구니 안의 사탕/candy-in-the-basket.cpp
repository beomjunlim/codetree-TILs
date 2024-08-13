#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000001];
long long sum[5000001];

int main() {
    int n,k;
    cin>>n>>k;

    int min_num = 1000001;
    int max_num = -1;

    for(int i=0; i<n; i++){
        int x,y;
        cin>>x>>y;
        arr[y] += x;
        min_num = min(min_num, y);
        max_num = max(max_num, y);
    }
    
    sum[0] = 0;

    for(int i=0; i<=max_num+2*k; i++){
        if(i==0)
            sum[0] = arr[0];
        else
            sum[i] = sum[i-1] + arr[i];
    }
    
    long long ans = 0;
    for(int i=min_num; i<=max_num; i++){
        ans = max(ans, sum[i+2*k] - sum[i] + arr[i]);

    }

    cout<<ans;
    return 0;
}