#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];
int sum[100001];

int main() {
    int n,q;
    cin>>n>>q;

    int max_num = 0;
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        arr[a] = 1;
        max_num = max(max_num, a);
    }

    for(int i=1; i<=max_num; i++){
        int num = 0;
        if(arr[i]==1)
            num = 1;
        sum[i] = sum[i-1] + num;
    }

    for(int i=0; i<q; i++){
        int a,b,ans;
        cin>>a>>b;
        if(b>max_num)
            sum[b] = sum[max_num];
        
        ans = sum[b] - sum[a-1];
        if(a>max_num)
            ans = 0;
        cout<<ans<<'\n';
    }
    return 0;
}