#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000001];
int sum[1000001];

int main() {
    int n,k;
    cin>>n>>k;

    int min_num = 1000001;
    int max_num = -1;

    for(int i=0; i<n; i++){
        int x,y;
        cin>>x>>y;
        arr[y] = x;
        min_num = min(min_num, y);
        max_num = max(max_num, y);
    }
    
    sum[max(min_num-1,0)] = 0;

    for(int i=min_num; i<=max_num; i++){
        sum[i] = sum[i-1] + arr[i];
    }
    
    int idx = -1;
    int ans = 0;
    for(int i=min_num; i<=max_num-2*k; i++){
        if(ans<sum[i+2*k] - sum[i] + arr[i]){
            idx = i;
            ans = sum[i+2*k] - sum[i] + arr[i];
        }
    }

    cout<<ans;
    return 0;
}